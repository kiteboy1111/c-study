#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<stdlib.h>
int main()
{
	int arr[3][4] = { {1,2,3},{4,5} };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("&arr[%d][%d]=%p\n",i,j,&arr[i][j]);

		}
		printf("\n");
	}
}
//int main()
//{
//	char arr4[] = "abcdef";
//	printf("%d", sizeof(arr4));
//	printf("%d", strlen(arr4));
//
//}
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		if (strcmp(password , "123456")==0)
//		{
//			printf("y");
//			break;
//		}
//	}
//	
//}


//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}
//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("���������룺");
//	scanf("%s", &password);
//	while ((ch = getchar()) != '\n')
//	{
//		; 
//	}
//	printf("��ȷ�ϣ�Y/N��");
//	ret = getchar();
//	if (ret == 'Y')
//		printf("ȷ�ϳɹ�\n");
//	else
//		printf("����ȷ��\n");
//	
//
//	return 0;
//
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("�ҵ��ˣ��±�Ϊ��%d",i);
//			break;
//		}
//		if (i == sz)
//		{
//			printf("�Ҳ���");
//		}
//
//	}
//	return 0;
//}

//int main()
//{
//	int n, sum = 1, s = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		sum = 1;
//		for (int i = 1; i <= n ; i++)
//		{
//			sum *= i;
//		}
//		s += sum;
//	}
//	printf("%d", s);
//	return 0;
//}

