#define _CRT_SECURE_NO_WARNINGS 1]
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define r 6//��
#define c ((r)*2+1) //��
#define f (c)/2//���е�1���±�
int main()
{
	int arr[r][c] = { 0 };
	arr[0][f] = 1;
	for (int i = 1; i < r; i++)//��д��ṹ
	{
		for (int j = 1; j < c; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
		}
	}
	for (int i = 0; i < r; i++)//�����
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 0)
				printf("    ");
			else
				printf("%4d", arr[i][j]);//��4�����ӡ�Ŀո�����ͬ��
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
//    printf("%d\n", final);//�����Ǯ��
//    return 0;
//}

/*
Chuckie Lucky Ӯ��100����Ԫ������������һ��ÿ��Ӯ��8%���ʻ�����ÿ������һ�죬Chuckieȡ��
10����Ԫ����дһ�����򣬼�����Ҫ������Chuckie�ͻ���������ʻ���
*/
//int main()
//{
//	double rate = 0.08;
//	double rate2 = 10.0;
//	double cash = 100.0; 
//	int years = 0;
//	do
//	{
//		cash -= rate2 - cash * rate; //cash-�������ֵ100-��10-100*0.08��
//		years++;
//	} while (cash > 0);
//	printf("%d���jackûǮȡ��", years);
//	return 0;
//}

//int main()
//5��Jack ��100 ��Ԫ����������8 % ���˻����ӵڶ��꿪ʼ��ÿ��ĵ�һ�죬���������˻���ȡ��10 ��Ԫ����дһ�����򣬼���������Jack��ȡ���˻���Ǯ��һ��ȡ�˶���Ǯ��
//
//���н����

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
//		printf("�����������㣺");
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
//	printf("���̸�Ϊ��%lf\n", x0);
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
//    if (x < 1)    //if ��else�Ľ�βû�зֺ�
//        y = x;
//    else if (x >= 1 && x < 10) //&&��Ϊ����
//        y = 2 * x + 1;
//    else                  //����if��ֻʣ���һ������
//        y = 3 * x - 8;
//    printf("y=%d", y);
//    return 0;
//}
//{
//	int num, a, b, c, d;
//	printf("������һ����λ������");
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
//	printf("������Բ�뾶��");
//	scanf("%f", &r);
//	printf("������Բ���ߣ�");
//	scanf("%f", &h);
//	C = 2 * PI * r;
//	S = PI * r * r;
//	V = PI * S * h;
//	printf("\nԲ�ܳ��ǣ�%.2f\n", C);
//	printf("\nԲ����ǣ�%.2f\n", S);
//	printf("\nԲ�����;%.2f\n", V);
//	return 0;
//}
