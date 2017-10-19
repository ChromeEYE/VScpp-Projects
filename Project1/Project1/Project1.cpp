// Project1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;
#define output_Length(a) (sizeof(a)/sizeof(a[0]))


int main()
{
	//現在時刻の変数
	time_t t1, t2;

	//ガイド用文字の配列と入力用配列
	char output[27] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	char input[27];

	//エンターで開始
	cout << "Enterキーで開始します\n";
	while (getchar() != '\n');
	for (int count = 3; count > 0; count--)
	{
		printf_s("%d\n", count);
		Sleep(1000);
	}

	t1 = time(NULL);

	//ガイドを出力し、入力を受け取る。間違いの場合はもう一度
	for (int i = 0; i < output_Length(output); i++)
	{
		cout << "\n" << output[i] << "=";
		cin >> input[i]; cout << "\n";
		if (input[i] != output[i])
		{
			cout << "\n間違い！もう一度！\n";
			i--;
		}
		else
		{
			
		}
	}

	t2 = time(NULL);

	int result = int(t2 - t1);

	cout << result << "秒\n";

	return 0;
}