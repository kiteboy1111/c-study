#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <time.h> 
int main()

{
	int a[20];
	int i, j;
	int n;
	scanf("%d", &n);//所需输出的行数 
	if (n == 1)//只有一行，输出即可 
		printf("1\n");
	else
	{
		a[0] = a[1] = a[2] = 1;
		printf("1\n1    1\n"); //两行的话直接输出 
		for (i = 3; i <= n; i++)//从第三行开始计算 
		{
			a[i - 1] = 1;//每行的最后一个数字都是1 
			for (j = i - 2; j > 0; j--)//倒着计算出每一行的数值 
				a[j] = a[j] + a[j - 1];
			a[0] = 1;//每行的第一个数字都是1 
			for (j = 0; j < i; j++)//计算完一行，输出一行。 
				printf("%-5d", a[j]);
			printf("\n");
		}
	}
	return 0;
}

//生成随机数的头文件
//void menu()//游戏菜单
//{
//	printf("********************\n");
//	printf("****** 1.play ******\n");
//	printf("****** 0.over ******\n");
//	printf("********************\n");
//}
//void game()//游戏程序
//{
//	int number, ask, times = 1;
//	long t;
//	srand((unsigned)time(NULL));
//	number = rand() % 100 + 1;
//	
//	printf("请输入您猜的数字（1-100）：");
//	scanf("%d", &ask);
//	t = time(NULL);
//	while (ask != number)
//	{
//		if (ask > number)
//		{
//			printf("\n您猜的数大了，请重新输入：");
//		};
//		if (ask < number)
//		{
//			printf("\n您猜的数字小了，请重新输入：");
//		};
//		scanf("%d", &ask);
//		times++;
//	}
//	t = time(NULL) - t;
//	printf("\n恭喜你！回答正确。您猜了%d次。用时%d秒\n", times, t);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch(input)
//		{
//			case 0:
//				printf("退出游戏\n");
//				break;
//			case 1:
//				printf("\n游戏开始了，朋友。");
//				game();
//				break;
//			default:
//				printf("选择错误，请重新选择！\n");
//				break;
//		}
//	} while (input);
//	return 0;
//}
//// 4、回到1
//int main()
//{
//	int i = 0;//控制行
//	int j = 0;//空格的循环次数
//	int k = 0;//*的循环次数
//	for (i = 1; i <= 7;i++)//第一部分：前7行。
//	{
//		for (j = 1; j <= 7 - i; j++)
//		{
//			printf(" ");
//		}
//		for (k = 1; k <= 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 1; i <= 6; i++)//第二部分：后6行
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (k = 1; k <= 13 - 2 * i; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//    int i;
//    int A[10];
//    int B[10];
//    int t[10];
//    printf("请输入数组A：");
//    for (i = 0; i < 10; i++)
//    {
//        scanf(" %d", &A[i]);
//    }
//    printf("请输入数组B：");
//    for (i = 0; i < 10; i++)
//    {
//        scanf(" %d", &B[i]);
//    }
//    for (i = 0; i < 10; i++)
//    {
//        t[i] = A[i];
//        A[i] = B[i];
//        B[i] = t[i];
//    }
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", A[i]);
//    }
//    printf("\n");//为了使结果看起来清晰，把数组A和数组B上下分隔开
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", B[i]);
//    }
//    printf("\n");
//    return 0;
//}
//int main()
//{
//	int a, b;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	if (a > b)
//	{
//		i = b;
//	}
//	else
//		i = a;
//	while (a % i != 0 || b % i != 0)
//	{
//		i--;
//	}
//	printf("%d", i);
//	return 0;
//}

//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//int main() {
//	int a[10];
//
//	int Max = 0;
//
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &a[i]);
//
//	}
//
//	for (int i = 0; i < 10; i++) {
//		if (a[i] > Max) {
//			Max = a[i];
//
//		}
//
//	}
//
//	printf("十个数中最大的是：%d", Max);
//
//	return 0;
//
//}