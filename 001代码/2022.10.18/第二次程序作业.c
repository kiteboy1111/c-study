#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", strlen("c:\test\32\test.c"));
	return 0;
}
//{
//	char arr2[] = { 'a','b','c',0 }; //0是结束标志
//	printf("%s\n", arr2);
//	char arr1[] = "abc";
//	printf("%s\n", arr1);
//
//	return 0;
//}
//{
//	int n, i;
//	printf("请输入整数：");
//	scanf("%d", &n);
//	printf("%d=", n);
//	for (i = 2; i <= n; i++)
//	{
//		while (n%i==0)
//		{
//			printf("%d", i);
//			n/=i;   //n除以i的商的整数部分，n%10 ,是得到n除以10以后的余数（取余
//			if (n!=1) printf("*"); //
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a=0, b=0,i=0;
//	scanf("%d%d", &a, &b);
//	for (i = a; i > 0; i--)
//	{
//		if (a % i == 0 && b % i == 0)
//		{
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}

//原文链接：https ://blog.csdn.net/qq_49663134/article/details/126128836
//#define SUM(x,y) ((x)+(y))
//int ADD(int x, int y) {
//	return x + y;
//}
//int main()
//{
//	//方法一
//	int x, y;
//	scanf("%d%d",&x,&y);
//	printf("%d\n", x + y);
//
//	//2.函数
//	int sum = ADD(x, y);
//	printf(" % d\n", sum);
//	
//	//3.定义宏
//	printf("%d\n",SUM(x,y));
//
//	return 0;
//}

