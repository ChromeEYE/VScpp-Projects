#include "stdafx.h"
#include "regulation.h"

using namespace std;

int squar[Ynumber][Xnumber];

int input()
{




	return 0;
}

int main()
{
	
	int f=0;
	for (int i = -1; i < Ynumber; i++)
	{
		if (i == -1)
		{
			cout << "┌";
			for (int j = 0; j < Xnumber; j++);
			{
				cout << "─┬";
			}
			cout << "─┐\n";
		}
		else
		{
			for (int j = 0; j < Xnumber; j++)
			{
				switch (squar[i][j])
				{
				default:
					cout << "│　";
					break;
				case 1:
					cout << "│○";
					break;
				case 2:
					cout << "│×";
					break;
				}
			}
			
			cout<< "│";

			if (i < Ynumber-1)
			{
				cout << "\n├";
				for (int j = 0; j < Xnumber; j++)
				{
					cout << "─┼";
				}
				cout << "─┤\n";
			}
			else
			{
				cout << "\n└";
				for (int j = 0; j < Xnumber; j++);
				{
					cout << "─┴";
				}
				cout << "─┘\n";
			}
		}
	}
	
	getchar();
	return 0;
}