#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int n = 0, k = 0;
	printf("������Ƶĸ�����1-100����\n");
	scanf("%d", &n);
	printf("�����������������ڵƵĸ�������\n");
	scanf("%d", &k);
	if (k >= n>1)
	{
		printf("û�е�����");
	}
	else if (1 == k == n)
	{
		printf("��һ��������");
	}
	else
	{
		int arr[100];
		memset(arr, 0, sizeof(arr));//ȫ����ֵΪ0
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (i % j == 0)
					arr[i] = arr[i] + 1;//�������ļ�1��
			}
		}
		printf("���ŵĵƱ��Ϊ��");
		for (int l = 1; l <= n; l++)
		{
			if (arr[l] % 2 != 0)//����2�ı����ĵļ�Ϊ���ŵģ���Ϊ���ŵĵ���Ϊ1
				printf(" %d", l);
		}
	}
}
//int main()
//{
//	printf("����һ��ʮ�����Ƶ�����");
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
//void other()//��һ�ַ���
//{
//	int a = 0;
//	printf("������һ��ʮ�����Ƶ�����\n");
//	scanf("%x", &a);
//	printf("ת�����ʮ������Ϊ��%d\n", a);
//
//}
//int main()
//{
//	int arr[] = {1,5,13,19,26,27,56,64,75,80,88,89,105,106,120};
//	int left = 0;
//	int right =sizeof(arr)/sizeof(arr[0])-1;
//	int k = 0;
//	printf("������Ҫ���ҵ����֣�");
//	scanf("%d", &k);
//	//�۰뷨
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
//			printf("�ҵ��ˣ��ǵ�%d��Ԫ��\n", mid+1);//�±�+1Ϊ�ڼ���Ԫ��
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}
////2.ѡ��
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
//	printf("�Ƚϴ���%d\n��������%d\n", count1, count2);
//	return 0;
//}
////1.ð�ݷ�
//int main()
//{
//	char arr[] = { 'q','w','e','r','t','y','u','M','o','p','e','\0' };//���'\0'��ʾ������
//	int count1 = 0, i = 0, count2 = 0;
//	int sz = strlen(arr);//int sz = sizeof(arr) / sizeof(arr[0])�������������
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
//	}//����ֱ��printf("%s",arr)����puts(arr)��ӡ��������
//	printf("����������%d\n", count1);
//	printf("�Ƚϴ�����%d\n", count2);
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

