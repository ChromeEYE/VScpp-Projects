#include "Header.h"

using namespace std;

char* strHigh = "high";
char* strLow = "low";

void shuffle(int array[], int size)
{
	int i = size;
	while (i > 1)
	{
		int j = rand() % i;
		i--;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}

char* char_number(int i)
{
	static char* rt_numb;
	switch (i)
	{
	default:
		_itoa(i, rt_numb, 10);
		break;
	case 1:
		rt_numb="A";
		break;
	case 11:
		rt_numb = "J";
		break;
	case 12:
		rt_numb = "Q";
		break;
	case 13:
		rt_numb = "K";
		break;
	}
	return rt_numb;
}

char* highlow(int array[],int i)
{
	static char* rt_highlow;
	if (array[i] < array[i+1])
	{
		rt_highlow = strHigh;
	}
	else if (array[i] > array[i+1])
	{
		rt_highlow = strLow;
	}
	return rt_highlow;
}

int main()
{
	int number[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int size = sizeof(number) / sizeof(int);
	shuffle(number, size);
	char s[5];
	for (int i = 0; i < size ; i++)
	{
		cout << char_number(number[i]) << endl << "次の数はこれより大きいか、小さいか" << endl << "大きいならhigh、小さいならlowと入力してください" << endl;
		cin >> s;
		char* a = highlow(number, i);
		if (strcmp(s, a) == 0)
		{
			cout << endl << "当たり！次の数字へどうぞ" << endl;
		}
		else
		{
			cout << endl << "おや、間違えましたね" << endl;
			i--;
		}
	}


	return 0;
}