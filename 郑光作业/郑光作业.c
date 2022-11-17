#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;//����
	int y = 0;
	printf("Player go\n");
	while (1)
	{
		printf("Please enter the coordinates of the chess game:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//������ȷ
		{
			if (board[x - 1][y - 1] == ' ')//��������ʱ
			{
				board[x - 1][y - 1] = '*';//����ҵ���
				break;
			}
			else
			{
				printf("The coordinates are occupied, please re-enter!\n");
			}
		}
		else
		{
			printf("The coordinates are wrong, please re-enter!\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("The computer go!\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')//������Ч
		{
			board[x][y] = '#';//��������
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//��
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//��
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//ƽ��
	int ret = IsFull(board, row, col);//�ж�����������
	if (ret == 1)
		return 'Q';
	return 'C';
}
//�涨:����C����,����*���Ӯ,����#����Ӯ,����Qƽ��
//��Ϸ�˵�
void menu()
{
	printf("*****************************\n");
	printf("******  1.play  *************\n");
	printf("******  0.exit  *************\n");
	printf("*****************************\n");
}
//��Ϸ����
void game()
{
	char board[ROW][COL] = { 0 };//����-�������
	InitBoard(board, ROW, COL);//��ʼ������-��ʼ���ո�
	DisplayBoard(board, ROW, COL);//��ӡ����-�����Ǵ�ӡ���������
	char ret = 0;
	while (1)
	{
		//�����->�ж�
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//������->�ж�
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("The player wins!");
	}
	else if (ret == '#')
	{
		printf("The computer wins!");
	}
	else
	{
		printf("Daw!");
	}
	DisplayBoard(board, ROW, COL);
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//���������,�õ�������
	do
	{
		menu();
		printf("Please select:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Start the game!\n");//���������˼
			game();
			break;
		case 0:
			printf("Exit the game!\n");
			break;
		default:
			printf("Select incorrectly, please select again!");
			break;
		}
	} while (input);
}


//int main()
//{
//	int ch;
//	printf("Please enter characters:");
//	while ((ch = getchar()) !=EOF)
//	{
//
//		if (ch >= 'a' && ch <= 'z')
//		{
//			printf("%c\n", ch - 32);
//			printf("Please enter characters:");
//			getchar();
//		}
//		else if (ch >= 'A' && ch <= 'Z')
//		{
//			printf("%c\n", ch + 32);
//			printf("Please enter characters:");
//			getchar();
//		}
//		else
//			break;
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char name[64];
//	char password[64];
//	int count = 3;
//	while (count > 0)
//	{
//		count--;//ȷ������
//		printf("Please enter your name��");
//		scanf("%s", name);//û��&
//		printf("Please enter your password��");
//		scanf("%s", password);
//		if (strcmp(USER, name) == 0 && strcmp(PASSWORD, password) == 0)
//		{
//			break;
//		}
//		else
//		{
//			printf("name or password error,try again!you have %d times\n", count);
//		}
//	}
//	if (count > 0)
//	{
//		printf("login sucess!\n");//������ϣ�����������ȴ�һ��,��������Ϸ��¼һ��
//		int i = 3;
//		while (i > 0)
//		{
//			printf("loading...%d\r", i);
//			Sleep(1000);//˯��1000ms
//			i--;
//		}
//		printf("loading...done!\n");
//	}
//	else
//	{
//		printf("Login failed\n");
//	}
//	system("pause");//��ͣһ��
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
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
//			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);//�±�+1Ϊ�ڼ���Ԫ��
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

