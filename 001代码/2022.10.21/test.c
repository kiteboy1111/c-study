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
    double x1, x2, xx;//x1,x2�����������ұ߽磬xx�����̸���ֵ
    do
    {
        scanf("%lf%lf", &x1, &x2);
    } while (f(x1) * f(x2) > 0);//��֤f(x1)��f(x2)����ţ������ſ��Խ�����һ���ľ�׼���䣬������������x1��x2��ֵ
    do
    {
        xx = (x1 + x2) / 2;
        if (f(xx) * f(x1) > 0)
            x1 = xx;
        else
            x2 = xx;
    } while (fabs(f(xx)) >= 1e-7);//le-6����1*10��-6�η�������ֵ��Ӱ�쵽����׼ȷ�ȵ�����
    printf("%.2lf\n", xx);
    return 0;
}

//{
//	
//	for (int n = 2; n < 2000; n++)
//	{//����2-1000���������� 
//		int sum = 0; //int sum = 0;���ܷ�����
//		for (int j = 1; j < n; j++)
//		{//����1��n֮�����������
//			if (n % j == 0)//���j��n������
//				sum += j;//�Ѿ�j�ӵ�����
//		}
//		if (sum == n) 
//		{//������Ӻ�sum��n��ȣ�i������ȫ��
//			printf("%d����ȫ��\n", n);	//���n����ȫ��
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
//    ///deno��ĸ��member���ӣ�sign����
//    while (index > 0.001)
//    {
//        sum += member / (deno * deno) * sign;
//        index = member / (deno * deno);
//        deno += 2;
//        member += 2;
//        sign = -sign;
//    }
//    sum += member / (deno * deno) * sign;
//    ///����ֱ��indexС��0.001��ֹͣ�Ӻͣ�������Ҫ��index
//    ///ǡ��С��0.001����һ�����
//    printf("s=%.6lf", sum);
//    return 0;
//}
