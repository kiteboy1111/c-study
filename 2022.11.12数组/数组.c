#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int n = 0, k = 0;
	printf("请输入灯的个数（1-100）：\n");
	scanf("%d", &n);
	printf("请输入人数（不大于灯的个数）：\n");
	scanf("%d", &k);
	if (k >= n>1)
	{
		printf("没有灯亮着");
	}
	else if (1 == k == n)
	{
		printf("第一个灯亮着");
	}
	else
	{
		int arr[100];
		memset(arr, 0, sizeof(arr));//全都赋值为0
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (i % j == 0)
					arr[i] = arr[i] + 1;//被整除的加1，
			}
		}
		printf("亮着的灯编号为：");
		for (int l = 1; l <= n; l++)
		{
			if (arr[l] % 2 != 0)//不是2的倍数的的即为亮着的，因为亮着的灯数为1
				printf(" %d", l);
		}
	}
}
//int main()
//{
//	printf("输入一个十六进制的数：");
//	char arr[] = { 0 };
//	scanf("%s", arr);
//	int t = strlen(arr);
//	long sum = 0;
//	for (int i = 0; arr[i]; i++)
//	{
//		if (arr[i] <= '9')
//			t = arr[i] - '0';
//		else
//			t = arr[i] - 'A' + 10;
//		sum = sum * 16 + t;
//	}
//	printf("%ld\n", sum);
//	return 0;
//}
//void other()//另一种方法
//{
//	int a = 0;
//	printf("请输入一个十六进制的数：\n");
//	scanf("%x", &a);
//	printf("转换后的十进制数为：%d\n", a);
//
//}
//int main()
//{
//	int arr[] = {1,5,13,19,26,27,56,64,75,80,88,89,105,106,120};
//	int left = 0;
//	int right =sizeof(arr)/sizeof(arr[0])-1;
//	int k = 0;
//	printf("请输入要查找的数字：");
//	scanf("%d", &k);
//	//折半法
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，是第%d个元素\n", mid+1);//下标+1为第几个元素
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}
////2.选择法
//int main()
//{
//	char arr[] = { 'q','w','e','r','t','y','u','M','o','p','e','\0' };
//	int count1 = 0, count2 = 0;
//	int sz = strlen(arr);
//	for (int i = 0; i < sz-1; i++)
//	{
//		int k = i;
//		for (int j = i + 1; j < sz; j++)
//		{
//			count1++;
//			if (arr[j] < arr[k])
//			{
//				k = j;
//			}
//		}
//		if (i != k)
//		{
//			count2++;
//			int t = arr[i];
//			arr[i] = arr[k];
//			arr[k] = t;
//		}
//	}
//	printf("%s\n", arr);
//	printf("比较次数%d\n交换次数%d\n", count1, count2);
//	return 0;
//}
////1.冒泡法
//int main()
//{
//	char arr[] = { 'q','w','e','r','t','y','u','M','o','p','e','\0' };//后加'\0'表示结束。
//	int count1 = 0, i = 0, count2 = 0;
//	int sz = strlen(arr);//int sz = sizeof(arr) / sizeof(arr[0])这个用在数字中
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			count2++;
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				count1++;
//			}
//		}
//	}
//	for (int k = 0; k < 11; k++)
//	{
//		printf("%c\n", arr[k]);
//	}//或者直接printf("%s",arr)或者puts(arr)打印整个数组
//	printf("交换次数：%d\n", count1);
//	printf("比较次数：%d\n", count2);
//	return 0;
//}









//////void bubble_sort(int arr[],int sz)
////{
////	int i = 0;
////	for (i = 0; i < sz; i++)
////	{
////		int flag = 1;
////		int j = 0;
////		for (j = 0; j < sz - 1 - i; j++)
////		{
////			if (arr[j] > arr[j + 1])
////			{
////				int tmp = arr[j];
////				arr[j] = arr[j + 1];
////				arr[j + 1] = tmp;
////				flag = 0;
////			}
////		}
////		if (1 == flag)
////		{
////			break;
////		}
////	}
////}
////
////int main()
////{
////	int i = 0;
////	int arr[] = {1,2,3,4,6,5,7,8,9,10};
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	//
////	bubble_sort(arr, sz);
////	for (i = 0; i < sz; i++)
////	{
////		printf("%d", arr[i]);
////	}
////	return 0;
////}

