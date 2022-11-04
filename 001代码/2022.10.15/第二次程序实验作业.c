#define _CRT_SECURE_NO_WARNINGS 1]
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define r 6//行
#define c ((r)*2+1) //列
#define f (c)/2//首行的1列下标
int main()
{
	int arr[r][c] = { 0 };
	arr[0][f] = 1;
	for (int i = 1; i < r; i++)//先写其结构
	{
		for (int j = 1; j < c; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
		}
	}
	for (int i = 0; i < r; i++)//后输出
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 0)
				printf("    ");
			else
				printf("%4d", arr[i][j]);//宽4，与打印的空格数相同。
		}
		printf("\n");
	}
	return 0;
}

//
//int k;                        
//int final = 0, day = 1, j = 1;          
//int main()
//
//{
//    scanf("%d", &k);
//    for (int i = 1; i <= k; i++)      
//    {
//
//        final += day;         
//        if (j == day)
//        {
//            day++;
//            j = 0;
//        }
//        j++;               
//    }
//    printf("%d\n", final);//输出总钱数
//    return 0;
//}

/*
Chuckie Lucky 赢了100万美元，他把它存入一个每年赢得8%的帐户。在每年的最后一天，Chuckie取出
10万美元。编写一个程序，计算需要多少年Chuckie就会清空他的帐户。
*/
//int main()
//{
//	double rate = 0.08;
//	double rate2 = 10.0;
//	double cash = 100.0; 
//	int years = 0;
//	do
//	{
//		cash -= rate2 - cash * rate; //cash-后面的总值100-（10-100*0.08）
//		years++;
//	} while (cash > 0);
//	printf("%d年后，jack没钱取了", years);
//	return 0;
//}

//int main()
//5、Jack 将100 美元存入年利率8 % 的账户。从第二年开始在每年的第一天，他会从这个账户里取出10 美元。编写一个程序，计算多少年后Jack会取完账户的钱？一共取了多少钱？
//
//运行结果：

//double f(double x)
//{
//	return (pow(x, 3) + 2*x - 5);
//}
//int main()
//{
//	double x1, x2, xx;
//	do
//	{
//		x1 = -1; x2 = 2;
//	}
//	while (f(x1) * f(x2) > 0);
//	do
//	{
//		xx = (x1 + x2) / 2;
//		if (f(x1) * f(xx) > 0)
//			x1 = xx;
//		else
//			x2 = xx;
//	}
//	while (fabs(f(xx)) >= 1e-4);
//	printf("%.4f\n", xx);
//	return 0;
//}
//int main() {
//	double x0, x1, x2, f0, f1, f2;
//	do {
//		printf("请输入两个点：");
//		scanf("%lf,%lf", &x1, &x2);
//		f1 = ((2 * x1 - 4) * x1 + 3) * x1 - 6;
//		f2 = ((2 * x2 - 4) * x2 + 3) * x2 - 6;
//		printf("f1 = %f, f2 = %f\n", f1, f2);
//	} while (f1 * f2 > 0);
//
//	do {
//		x0 = (x1 + x2) / 2;
//		f0 = ((2 * x0 - 4) * x0 + 3) * x0 - 6;
//		if (f0 * f1 < 0) {
//			x2 = x0;
//			f2 = f0;
//		}
//		else {
//			x1 = x0;
//			f1 = f0;
//		}
//	} while (fabs(f0) >= 0.00001);
//	printf("方程根为：%lf\n", x0);
//
//	return 0;
//}

//int main()
//{
//	int a, b, c, d, t;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//
//	if (a > b)
//	{
//		t = a; a = b; b = t;
//	}
//	if (a > c)
//	{
//		t = a; a = c; c = t;
//	}
//	if (a > d)
//	{
//		t = a; a = d; d = t;
//	}
//	if (b > c)
//	{
//		t = b; b = c; c = t;
//	}
//	if (b > d)
//	{
//		t = b; b = d; d = t;
//	}
//	if (c > d)
//	{
//		t = c; c = d; d = t;
//	}
//	printf("%d,%d,%d,%d", a, b, c, d);
//	return 0;
//
//}
//{
//    int x, y;
//    scanf("%d", &x);
//    if (x < 1)    //if 和else的结尾没有分号
//        y = x;
//    else if (x >= 1 && x < 10) //&&意为或者
//        y = 2 * x + 1;
//    else                  //不加if，只剩最后一个区间
//        y = 3 * x - 8;
//    printf("y=%d", y);
//    return 0;
//}
//{
//	int num, a, b, c, d;
//	printf("请输入一个四位整数：");
//	scanf("%d", &num);
//	a = num % 10;
//	b = num / 10 % 10;
//	c = num / 100 % 10;
//	d = num / 1000 % 10;
//	printf("%d %d %d %d", a, b, c, d);
//	return 0;
//    
//}
//#define PI 3.14159

//int main()
//{
//	float r, h, C, S, V;
//	printf("请输入圆半径：");
//	scanf("%f", &r);
//	printf("请输入圆柱高：");
//	scanf("%f", &h);
//	C = 2 * PI * r;
//	S = PI * r * r;
//	V = PI * S * h;
//	printf("\n圆周长是：%.2f\n", C);
//	printf("\n圆面积是：%.2f\n", S);
//	printf("\n圆体积是;%.2f\n", V);
//	return 0;
//}
