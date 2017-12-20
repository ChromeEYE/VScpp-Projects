#include "Header.h"

using namespace std;

int board[VERTICAL + 1][HORIZONTAL + 1];

int main()
{
	board_set();
	char* num_str[] = { "１", "２", "３", "４", "５", "６", "７", "８", "９" };

	while (true)
	{
		//描画
		cout << "　１２３４５６７８" << endl;
		for (int i = 0; i < VERTICAL; i++)
		{
			cout << num_str[i];
			for (int j = 0; j < HORIZONTAL; j++)
			{
				cout << return_sell(board[i][j]);
			}
			cout << endl;
		}

		//勝敗判定
		bool sell_bool = false;
		for (int i = 0; i < VERTICAL; i++)
		{
			for (int j = 0; j < HORIZONTAL; j++)
			{
				if (0 == board[i][j])
				{
					sell_bool = true;
					break;
				}
			}
			if (sell_bool)break;
		}
		if (!sell_bool)
		{
			cout << "ゲーム終了" << endl;
			getchar();
			break;
		}


	}
	getchar();

	return 0;
}

void board_set()
{
	static int initdata[VERTICAL][HORIZONTAL] =
	{ { 0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  2,  1,  0,  0,  0 },
	{ 0,  0,  0,  1,  2,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0 },
	{ 0,  0,  0,  0,  0,  0,  0,  0 } };


	for (int i = 0; i < VERTICAL; i++)
	{
		for (int j = 0; j < HORIZONTAL; j++)
		{
			board[i][j] = initdata[i][j];
		}
	}
}

char* return_sell(int number)
{
	switch (number)
	{
	default:
		break;
	case 0:
		return "□";
		break;
	case 1:
		return "○";
		break;
	case 2:
		return "●";
		break;
	}
}