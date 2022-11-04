#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
double f(double x)
{
    return (x * x * x - 3 * x * x + 3 * x - 1);
}
int main()
{
    double x1, x2, xx;//x1,x2代表区间左右边界，xx代表方程跟的值
    do
    {
        scanf("%lf%lf", &x1, &x2);
    } while (f(x1) * f(x2) > 0);//保证f(x1)和f(x2)是异号，这样才可以进行下一步的精准区间，否则，重新输入x1，x2的值
    do
    {
        xx = (x1 + x2) / 2;
        if (f(xx) * f(x1) > 0)
            x1 = xx;
        else
            x2 = xx;
    } while (fabs(f(xx)) >= 1e-7);//le-6代表1*10的-6次方，它的值将影响到跟的准确度的问题
    printf("%.2lf\n", xx);
    return 0;
}

//{
//	
//	for (int n = 2; n < 2000; n++)
//	{//遍历2-1000的所有数字 
//		int sum = 0; //int sum = 0;不能放外面
//		for (int j = 1; j < n; j++)
//		{//遍历1到n之间的所有数字
//			if (n % j == 0)//如果j是n的因子
//				sum += j;//把就j加到和中
//		}
//		if (sum == n) 
//		{//如果因子和sum与n相等，i就是完全数
//			printf("%d是完全数\n", n);	//输出n是完全数
//		}
//	}
//}
//
//{
//	double s = 0, t, n = 1, i = 1;
//	do {
//		t = i * (2 * n + 1) / pow((2 * n), 2);
//		i = -i;
//		s += t;
//		n++;
//	} while ((2.0 * n + 1) / pow((2 * n), 2) > 0.001);
//	printf("%.6f", s);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//    float sum = 0, deno = 2, member = 3, sign = 1, index = 1;
//    ///deno分母，member分子，sign符号
//    while (index > 0.001)
//    {
//        sum += member / (deno * deno) * sign;
//        index = member / (deno * deno);
//        deno += 2;
//        member += 2;
//        sign = -sign;
//    }
//    sum += member / (deno * deno) * sign;
//    ///由于直到index小于0.001才停止加和，故许需要把index
//    ///恰好小于0.001的那一项加上
//    printf("s=%.6lf", sum);
//    return 0;
//}
