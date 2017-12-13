// Project31.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int main()
{
	FILE *fp;

	if ((fp = fopen("mono.bmp", "rb")) == NULL)//ファイルを開く
	{
		std::cout << "error: Failed file open!!";//エラーテキスト
		return -1;
	}

	fseek(fp, 0, SEEK_END);//ファイル末尾に移動
	int position = ftell(fp);//ファイル末尾の位置を取得　＝　ファイルサイズ
	unsigned char* buff = (unsigned char*)malloc(position);// メモリ確保

	if (buff == NULL)
	{
		std::cout << "error: Failed memory alloced!!";//エラーテキスト
		fclose(fp);
		return -1;
	}

	fseek(fp, 0, SEEK_SET);//ファイル先頭に移動

	int n = fread(buff, position, 1, fp);//position=size サイズ1個分をbuffに明記

	if (n < 1)
	{
		std::cout << "error: Failed read function!!";//エラーテキスト
		free(buff);
		fclose(fp);
		return -1;
	}

	//buff[0]=1byte目のデータ
	int count = 0;
	for (int i = position - (16 * 16); i < position; i++)
	{
		printf("%02x", buff[i]);
		count++;
		if (count % 16 == 0)
		{
			std::cout << "\n";
		}
	}
	free(buff);//メモリ開放
	fclose(fp);//ファイルを閉じる

	//この方法ではcoutは使えない、逆に考えれば、どちらか一方のみに統一するというのは手段の閉塞を生むので柔軟に考えるべき

    return 0;
}

