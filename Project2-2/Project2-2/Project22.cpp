// Project22.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#define _CRT_SECURE_NO_WARNINGS 1
#include "stdafx.h"




int main()
{
	FILE* fl;
	char labyrinth[15][35];
	char buff[256];
	bool u, d, r, l;

	if ((fl = fopen("labyrinth.txt", "rt")) == NULL)
	{
		printf("file open error!");
		return -1;
	}

	fgets(buff, 256, fl);  printf("横　%s", buff);
	fgets(buff, 256, fl);  printf("縦　%s", buff);
		
	for (int i = 0; i < 15; i++)
	{
		fgets(buff, 256, fl);
		for (int j = 0; j < 35; j++)
		{
			switch (buff[j])
			{
			case '0':
				labyrinth[i][j] = '0';
				break;
			case '1':
				labyrinth[i][j] = '1';
				break;
			case '2':
				labyrinth[i][j] = '2';
				break;
			case '3':
				labyrinth[i][j] = '3';
				break;
			}
		}
	}

	fclose(fl);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			switch (labyrinth[i][j])
			{
			case 0:
				std::cout << "　";
				break;
			case 1:
				if (i != 0)  u = (labyrinth[i - 1][j] == '1');
				if (i != 15 - 1)  d = (labyrinth[i + 1][j] == '1');
				if (i != 0)  l = (labyrinth[i][j - 1] == '1');
				if (i != 35 - 1)  r = (labyrinth[i][j + 1] == '1');

				if (u && d && l &&r)  std::cout << "┼";
				else if (!u && d && l && r) std::cout << "┬";
				else if (u && !d && l && r) std::cout << "┴";
				else if (u && d && !l && r) std::cout << "├";
				else if (u && d && l && !r) std::cout << "┤";
				else if (!u && !d && l && r) std::cout << "─";
				else if (!u && d && !l && r) std::cout << "┌";
				else if (!u && d && l && !r) std::cout << "┐";
				else if (u && !d && !l && r) std::cout << "└";
				else if (u && !d && l && !r) std::cout << "┘";
				else if (u && d && !l && !r) std::cout << "│";
			case 2:
				std::cout << "○";
				break;
			case 3:
				std::cout << "×";
				break;
			}
		}
		std::cout << "\n";
	}

    return 0;
}

