#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <time.h> 
int main()

{
	int a[20];
	int i, j;
	int n;
	scanf("%d", &n);//������������� 
	if (n == 1)//ֻ��һ�У�������� 
		printf("1\n");
	else
	{
		a[0] = a[1] = a[2] = 1;
		printf("1\n1    1\n"); //���еĻ�ֱ����� 
		for (i = 3; i <= n; i++)//�ӵ����п�ʼ���� 
		{
			a[i - 1] = 1;//ÿ�е����һ�����ֶ���1 
			for (j = i - 2; j > 0; j--)//���ż����ÿһ�е���ֵ 
				a[j] = a[j] + a[j - 1];
			a[0] = 1;//ÿ�еĵ�һ�����ֶ���1 
			for (j = 0; j < i; j++)//������һ�У����һ�С� 
				printf("%-5d", a[j]);
			printf("\n");
		}
	}
	return 0;
}

//�����������ͷ�ļ�
//void menu()//��Ϸ�˵�
//{
//	printf("********************\n");
//	printf("****** 1.play ******\n");
//	printf("****** 0.over ******\n");
//	printf("********************\n");
//}
//void game()//��Ϸ����
//{
//	int number, ask, times = 1;
//	long t;
//	srand((unsigned)time(NULL));
//	number = rand() % 100 + 1;
//	
//	printf("���������µ����֣�1-100����");
//	scanf("%d", &ask);
//	t = time(NULL);
//	while (ask != number)
//	{
//		if (ask > number)
//		{
//			printf("\n���µ������ˣ����������룺");
//		};
//		if (ask < number)
//		{
//			printf("\n���µ�����С�ˣ����������룺");
//		};
//		scanf("%d", &ask);
//		times++;
//	}
//	t = time(NULL) - t;
//	printf("\n��ϲ�㣡�ش���ȷ��������%d�Ρ���ʱ%d��\n", times, t);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch(input)
//		{
//			case 0:
//				printf("�˳���Ϸ\n");
//				break;
//			case 1:
//				printf("\n��Ϸ��ʼ�ˣ����ѡ�");
//				game();
//				break;
//			default:
//				printf("ѡ�����������ѡ��\n");
//				break;
//		}
//	} while (input);
//	return 0;
//}
//// 4���ص�1
//int main()
//{
//	int i = 0;//������
//	int j = 0;//�ո��ѭ������
//	int k = 0;//*��ѭ������
//	for (i = 1; i <= 7;i++)//��һ���֣�ǰ7�С�
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
//	for (i = 1; i <= 6; i++)//�ڶ����֣���6��
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
//    printf("����������A��");
//    for (i = 0; i < 10; i++)
//    {
//        scanf(" %d", &A[i]);
//    }
//    printf("����������B��");
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
//    printf("\n");//Ϊ��ʹ���������������������A������B���·ָ���
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
//	printf("ʮ�����������ǣ�%d", Max);
//
//	return 0;
//
//}