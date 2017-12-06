#include "Header.h"

using namespace std;

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

int main()
{
	int values[99];
	int size = sizeof(values) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		values[i] = i + 1;
	}
	shuffle(values, size);
	char s[300] = "";
	cout << "エンターキーを押してください\n";
	for (int i = 0; i < size; i++)
	{
		getchar();
		cout << "エンターキーを押してください\n";
		getchar();
		cout << values[i];
	}

	cout << "総ての数字が選出されました、終了します。";

	getchar();
	return 0;
}