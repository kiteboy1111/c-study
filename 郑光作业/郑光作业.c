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
	int x = 0;//坐标
	int y = 0;
	printf("Player go\n");
	while (1)
	{
		printf("Please enter the coordinates of the chess game:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//坐标正确
		{
			if (board[x - 1][y - 1] == ' ')//坐标无子时
			{
				board[x - 1][y - 1] = '*';//下玩家的子
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
		if (board[x][y] == ' ')//坐标有效
		{
			board[x][y] = '#';//电脑下子
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
	for (i = 0; i < row; i++)//行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	int ret = IsFull(board, row, col);//判断棋盘满了吗
	if (ret == 1)
		return 'Q';
	return 'C';
}
//规定:返回C继续,返回*玩家赢,返回#电脑赢,返回Q平局
//游戏菜单
void menu()
{
	printf("*****************************\n");
	printf("******  1.play  *************\n");
	printf("******  0.exit  *************\n");
	printf("*****************************\n");
}
//游戏代码
void game()
{
	char board[ROW][COL] = { 0 };//数组-存放棋盘
	InitBoard(board, ROW, COL);//初始化棋盘-初始化空格
	DisplayBoard(board, ROW, COL);//打印棋盘-本质是打印数组的内容
	char ret = 0;
	while (1)
	{
		//玩家下->判断
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下->判断
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
	srand((unsigned int)time(NULL));//生成随机数,让电脑下子
	do
	{
		menu();
		printf("Please select:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("Start the game!\n");//三子棋的意思
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
//		count--;//确保三次
//		printf("Please enter your name：");
//		scanf("%s", name);//没有&
//		printf("Please enter your password：");
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
//		printf("login sucess!\n");//这里我希望输入密码后等待一会,就像玩游戏登录一样
//		int i = 3;
//		while (i > 0)
//		{
//			printf("loading...%d\r", i);
//			Sleep(1000);//睡眠1000ms
//			i--;
//		}
//		printf("loading...done!\n");
//	}
//	else
//	{
//		printf("Login failed\n");
//	}
//	system("pause");//暂停一下
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
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
//			printf("找到了，下标为：%d\n", mid);//下标+1为第几个元素
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

