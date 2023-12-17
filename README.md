# 技术方案

## 32bit-ALU

verilog语言设计，6种运算：

- 32位无符号数加法、32位无符号数移位、32位无符号数截断

- 32数逻辑与、32位数逻辑或、32位数逻辑非

- 32位数逻辑异或

  功能表：

  | op   | ALU功能     | 功能说明     |
  | ---- | ----------- | ------------ |
  | 000  | ADD         | 超前进位加法 |
  | 001  | SHIFT_LEFT  | 逻辑左移     |
  | 010  | SHIFT_RIGHT | 逻辑右移     |
  | 011  | AND         | 按位与       |
  | 100  | OR          | 按位或       |
  | 101  | NOT         | 按位非       |
  | 110  | XOR         | 按位异或     |
  | 111  | OFF         | 截断         |

标志位：只有一个加法溢出的标志位：**cout**

## 设计方法：

在设计过程中，在顶层模块的ALU中，由于使用了时序逻辑和组合逻辑，所以在**always**块中不能实列化其他模块，所以创建了其他寄存器保存模块的值，在always块中使用，便于输出。

# 代码：

## 源码：

```verilog
module ALU(
    input [31:0] in1, // 第一个操作数
    input [31:0] in2, // 第二个操作数
    input [2:0] op, // 操作码，用来选择执行的操作
    output reg [31:0] result, // ALU 输出
    output reg cout//进位
    
);

// 定义操作码
parameter ADD = 3'b000;
parameter SHIFT_LEFT = 3'b001;
parameter SHIFT_RIGHT = 3'b010;
parameter AND = 3'b011;
parameter OR = 3'b100;
parameter NOT = 3'b101;
parameter XOR = 3'b110;
parameter OFF = 3'b111;

wire tcout;				//临时存入加法器的输出
wire [31:0] tresult;
CLA_adder32 add111(
    .cin(1'b0),
    .x(in1),
    .y(in2),
    .cout(tcout),
    .s(tresult)
);

always @ (*)
begin
    case(op)
        ADD:begin result = tresult;
        cout = tcout;
         end
  
        SHIFT_LEFT: result = in1 << in2; // 左移
        
        SHIFT_RIGHT: result = in1 >> in2; // 右移
        
        AND: result = in1 & in2; // 逻辑与
        
        OR: result = in1 | in2; // 逻辑或
        
        NOT: result = ~in1; // 逻辑非
        
        XOR: result = in1 ^ in2; // 逻辑异或
        
        OFF: begin//截断
        result = in1<< (32 - in2);
        result = result>>(32 - in2);
        end
        default: result = 0; // 默认情况，输出0
    endcase
end

endmodule
	//			超前进位加法器			教材p175//
  module full_adder(
  cin,x,y,cout,s
      );
      input [31:0] x,y;
      input cin;
      output cout;
      output [31:0] s;
      assign {cout,s}=cin+x+y;
  endmodule

module CLA_adder8(
cin,a,b,
cout,s
    );
    input [7:0] a,b;
    input cin;
    output [7:0] s;
    output cout;
    wire [7:0] G,P;
    wire [7:0] C;
    
    assign G[0]=a[0]&b[0];
    assign P[0]=a[0]|b[0];
    assign C[0]=cin;
    assign s[0]=a[0]^b[0]^C[0];
    
    assign G[1]=a[1]&b[1];
    assign P[1]=a[1]|b[1];
    assign C[1]=G[0]|(P[0]&cin);
    assign s[1]=a[1]^b[1]^C[1];
    
    assign G[2]=a[2]&b[2];
    assign P[2]=a[2]|b[2];
    assign C[2]=G[1] | (P[1]&G[0]) | (P[1]&P[0]&cin);
    assign s[2]=a[2]^b[2]^C[2];
    
    assign G[3]=a[3]&b[3];
    assign P[3]=a[3]|b[3];
    assign C[3]=G[2] | (P[2]&G[1]) | (P[2]&P[1]&G[0]) | (P[2]&P[1]&P[0]&cin);
    assign s[3]=a[3]^b[3]^C[3];
    
    assign G[4]=a[4]&b[4];
    assign P[4]=a[4]|b[4];
    assign C[4]=G[3] | (P[3]&G[2]) | (P[3]&P[2]&G[1]) | (P[3]&P[2]&P[1]&G[0]) |    						(P[3]&P[2]&P[1]&P[0]&cin);
    assign s[4]=a[4]^b[4]^C[4];
    
    assign G[5]=a[5]&b[5];
    assign P[5]=a[5]|b[5];
    assign C[5]=G[4] | (P[4]&G[3]) | (P[4]&P[3]&G[2]) | (P[4]&P[3]&P[2]&G[1]) | 						(P[4]&P[3]&P[2]&P[1]&G[0]) |
                (P[4]&P[3]&P[2]&P[1]&P[0]&cin);
    assign s[5]=a[5]^b[5]^C[5];
    
    assign G[6]=a[6]&b[6];
    assign P[6]=a[6]|b[6];
    assign C[6]=G[5] | (P[5]&G[4]) | (P[5]&P[4]&G[3]) | (P[5]&P[4]&P[3]&G[2]) | 						(P[5]&P[4]&P[3]&P[2]&G[1]) |
                (P[5]&P[4]&P[3]&P[2]&P[1]&G[0]) | (P[5]&P[4]&P[3]&P[2]&P[1]&P[0]&cin);
    assign s[6]=a[6]^b[6]^C[6];
    
    assign G[7]=a[7]&b[7];
    assign P[7]=a[7]|b[7];
    assign C[7]=G[6] | (P[6]&G[5]) | (P[6]&P[5]&G[4]) | (P[6]&P[5]&P[4]&G[3]) | 						(P[6]&P[5]&P[4]&P[3]&G[2]) |(P[6]&P[5]&P[4]&P[3]&P[2]&G[1]) | 							(P[6]&P[5]&P[4]&P[3]&P[2]&P[1]&G[0]) |
        		(P[6]&P[5]&P[4]&P[3]&P[2]&P[1]&P[0]&cin);
    assign s[7]=a[7]^b[7]^C[7];
    
    assign cout=G[7] | (P[7]&G[6]) | (P[7]&P[6]&G[5]) | (P[7]&P[6]&P[5]&G[4]) | 						(P[7]&P[6]&P[5]&P[4]&G[3]) |(P[7]&P[6]&P[5]&P[4]&P[3]&G[2]) | 							(P[7]&P[6]&P[5]&P[4]&P[3]&P[2]&G[1]) |
        		(P[7]&P[6]&P[5]&P[4]&P[3]&P[2]&P[1]&G[0]) |
        		(P[7]&P[6]&P[5]&P[4]&P[3]&P[2]&P[1]&P[0]&cin);
endmodule

module CLA_adder32(
cin,x,y,
cout,s
    );
    input [31:0] x,y;
    input cin;
    output [31:0] s;
    output cout;
    wire cout1,cout2,cout3;
    CLA_adder8 step1(cin,x[7:0],y[7:0],cout1,s[7:0]);
    CLA_adder8 step2(cout1,x[15:8],y[15:8],cout2,s[15:8]);
    CLA_adder8 step3(cout2,x[23:16],y[23:16],cout3,s[23:16]);
    CLA_adder8 step4(cout3,x[31:24],y[31:24],cout,s[31:24]);
endmodule
```

以下是4位超前进位加法器74HC283电路图：

![11b0cba854c0c9dbef55e19757cbf72](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\11b0cba854c0c9dbef55e19757cbf72.png)

## vivado仿真：

### 仿真电路图：

顶层ALU：

![56285f3788e5898a8b9543903e8d2f0](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\56285f3788e5898a8b9543903e8d2f0.png)

32位加法器：

![c803aef7c41db8622897591fedf608f](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\c803aef7c41db8622897591fedf608f.png)

8位加法器：

![f6596d55e67c4d8601adbc3ca852389](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\f6596d55e67c4d8601adbc3ca852389.png)

### 仿真测试：（测试代码以及结果图）

测试代码：

```verilog
module ALU_test();

    // 信号声明
    reg [31:0] in1, in2;
    reg [2:0] op;
    wire [31:0] result;
    wire cout;

    // 实例化ALU模块
    ALU ALU_instance(
        .in1(in1),
        .in2(in2),
        .op(op),
        .result(result),
        .cout(cout)
      
    );

    // 初始化
    initial 
    begin
    //ADD
        op = 3'b000;
        in1=32'hf3240000;
        in2=32'hf3240000;
    #20 in1=32'h00000fff;
        in1=32'h00000111;
    #20 in1=32'h0000ffff;
        in1=32'h00001111;
    #20 in1=32'hffffffff;
        in2=32'h00000001;
    //SHIFT_LEFT
    #20 op = 3'b001;
        in1=32'hffffffff;
        in2=32'h00000001;
    #20 in1=32'hffffffff;
        in2=32'h00000002;
    #20 in1=32'hffffffff;
        in2=32'h00000003;    
    // SHIFT_RIGHT
    #20 op = 3'b010;
        in1=32'hffffffff;
        in2=32'h00000001;
    #20 in1=32'hffffffff;
        in2=32'h00000002;
    #20 in1=32'hffffffff;
        in2=32'h00000003;       
    //   AND 
    #20 op = 3'b011;
        in1=32'hffffffff;
        in2=32'h00000001;
    #20 in1=32'hffffffff;
        in2=32'h00000002;
    #20 in1=32'hffffffff;
        in2=32'h00000003;    
    //   OR   
    #20 op = 3'b100;
        in1=32'hffffffff;
        in2=32'h00000001;
    #20 in1=32'hffffffff;
        in2=32'h00000002;
    #20 in1=32'hffffffff;
        in2=32'h00000003;   
    //  NOT    
    #20 op = 3'b101;
        in1=32'hffffffff;
        
    #20 in1=32'h00000000;
        
    #20 in1=32'hf0f0f0f0;
    //   XOR   
    #20 op = 3'b110;
        in1=32'hffffffff;
        in2=32'h00000001;
    #20 in1=32'hffffffff;
        in2=32'h00000002;
    #20 in1=32'hffffffff;
        in2=32'h00000003;
    //    off    
    #20 op = 3'b111;
        in1=32'hffffffff;
        in2=32'h00000001;
    #20 in1=32'hffffffff;
        in2=32'h00000002;
    #20 in1=32'hffffffff;
        in2=32'h00000003;    
    end
endmodule
```



测试结果：

<img src="D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\37a1256a615f98f7a765a5c811d7823.png" alt="37a1256a615f98f7a765a5c811d7823" style="zoom:200%;" />

![7f10b03b07d76b100555ad66fbba70b](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\7f10b03b07d76b100555ad66fbba70b.png)

经过验证，结果都正确。

# 结果展示：

## 云端FPGA验证：

### 加法器：

![e0b5a10ee4992ee320523e7dfa8bf31](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\e0b5a10ee4992ee320523e7dfa8bf31.png)

![5306a3186eecd496e87cd6e50cfb386](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\5306a3186eecd496e87cd6e50cfb386.png)

### 逻辑左移：

![fb46e192dbc9718e0a63d66d96d61f2](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\fb46e192dbc9718e0a63d66d96d61f2.png)

![085b3dfd3774d1e12b61d98d61aa021](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\085b3dfd3774d1e12b61d98d61aa021.png)

### 逻辑右移：

![6b19aac8f18de8feb9c67b7f84ac9f4](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\6b19aac8f18de8feb9c67b7f84ac9f4.png)

![b8cd526787564dc6fd4722b1ba1065f](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\b8cd526787564dc6fd4722b1ba1065f.png)

### 按位与：

![af7c26410d710efa62670f17f74ceee](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\af7c26410d710efa62670f17f74ceee.png)

![9c3ee8f50e11a2894dcda1dbe6505ed](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\9c3ee8f50e11a2894dcda1dbe6505ed.png)

### 按位或：

![d980d0221ea5ea1a4792737ea110601](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\d980d0221ea5ea1a4792737ea110601.png)

![d6149a9e56e8e41c439e324f5e283b2](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\d6149a9e56e8e41c439e324f5e283b2.png)

### 非运算：

![8e448adb60d3cbd76ae765b0ae2f3fc](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\8e448adb60d3cbd76ae765b0ae2f3fc.png)

![63b8a57a79ada5cd4ca932b5e6370fd](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\63b8a57a79ada5cd4ca932b5e6370fd.png)

### 按位异或：

![392ee1baf11eb5c7727f57a18a4f01a](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\392ee1baf11eb5c7727f57a18a4f01a.png)

![328a4b91850ca1b9a3d798743f08801](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\328a4b91850ca1b9a3d798743f08801.png)

### 截断：

![b9b337e7ca3ae16fa0880fd1ff50211](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\b9b337e7ca3ae16fa0880fd1ff50211.png)

![059a09c6830acfefd88bd0f3443f2f0](D:\WeChat Files\wxid_jzn0i8ri6f3b22\FileStorage\Temp\059a09c6830acfefd88bd0f3443f2f0.png)

# 遇到的问题：

## 设计过程的问题：

### 1.不熟悉Verilog语言

> 由于不熟悉Verilog语言，只了解了基础语法，真是寸步难行，一开始只
>
> 设计了最简单的32位ALU，每个功能几乎只用一行代码。

#### **task的尝试**

> 后来想加入加法模块，采用了**task**方法（因为我们采用了时序逻辑的方法设计，always语句下不允许调用module实例）
>
> 任务（task）可以用来描述共同的代码段，并在模块内任意位置被调用，让代码更加的直观易读。任务可以调用函数和任务，可以作为一条单独的语句出现语句块中。需要强调的是，任务在执行的时候是按语句顺序执行的，所以需要在编写相关功能时考虑到。
>
> 然后再vivado运行时，能仿真，但不能综合，Debug半天后发现无果，果断换方法，就是再always块外面其他实例化模块，临时创建寄存器保存下来，在always块在赋值给输出。这样的劣势是，当你不选择用这个模块时，这个模块还是会被调用，所以，这让效率变低和占用了更多的电路。

### 2.不熟悉云端FPGA的环境配置

我看着老师发的文档，一步步跟着教程走，你根本不理解文档内有些步骤为什么要这么做，所以只能按部就班，所以说，你就会犯错，你会漏看一些东西

例如

- use_top.v文件的修改
- IP核封装时，为什么要注释输出寄存器？
- IP核封装，要怎么写用户逻辑呢？
- 文档里正确的示范，如果遇到意料之外的报错，应该怎么办呢？
- 云端编译报错怎么修改？

对于以上问题，我劝大家不要自己去琢磨，直接找助教，或者去群里问问，因为大家可能遇到了一样的问题，多和自己的组员交流，分配任务。这可以快速解决，一般来说，上网寻找，可以解决你90%的问题了。

# 经验收获：

## 学习新事物

在学习怎么设计的时候，你得学习**Verilog**语言和相关电路知识，所以，你可以到学习通里面寻找课程，或者一些学习网站找网课。也可以通过同学的推荐的东西进行学习



## 团队合作

### 分配任务

> 我觉得在开始着手大作业之前，应该分配好每个人应该做的事，不然有些人就会混水摸鱼，导致他们什么都没学到，也不能全怪他们，要给他们主动分配任务。
>
> 分配任务也能高效地完成作业
>
> 

### 交流心得

> 因为每个人都做不一样的事，组员就得互相交流，遇到困难一起解决。例如我设计代码，而他们上传云端FPGA，我就得告诉他们我写的代码逻辑和设计思路。
