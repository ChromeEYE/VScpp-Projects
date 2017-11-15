// Project41.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <Windows.h>
#include <stdlib.h>
#include <wingdi.h>


int main()
{
	//ファイルを読み込み、失敗した場合エラー文を表示
	FILE *fp;
	if ((fp = fopen("img_format_256.bmp", "rb")) == NULL)
	{
		cout << "ERROR : Failed file opend.\n";
		fclose(fp);
		return -1;
	}

	//ファイルサイズを変数sizeに明記、シークで終端に移動し、int変数に現在地を渡してから先端に戻る
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	//メモリを確保、失敗した場合(ry
	unsigned char* buff;
	if ((buff = (unsigned char*)malloc(size)) == NULL)
	{
		cout << "ERROR : Failed alloced.\n";
		fclose(fp);
		return -1;
	}

	if (size != fread(buff, 1, size, fp))
	{
		cout << "ERROR : Failed read file.\n";
		fclose(fp);
		free(buff);
		return -1;
	}

	//BITMAPFILEHEADERポインタ変数pbfhに、BITMAPFILEHEADERポインタ形式に直したbuffを代入
	//BITMAPINFOHEADERポインタ変数pbihに、BITMAPINFOHEADERポインタ形式に直したbuffとBITMAPFILEHEADERのデータサイズの和を代入
	BITMAPFILEHEADER* pbfh = (BITMAPFILEHEADER*)buff;
	BITMAPINFOHEADER* pbih = (BITMAPINFOHEADER*)(buff + sizeof(BITMAPFILEHEADER));

	//コンソールに表示、-> = arrow演算子（クラスの要素を抽出）
	cout << "BITMAPFILEHEADER";
	cout << "\nbfType = " << pbfh->bfType;
	cout << "\nbfSize = " << pbfh->bfSize;
	cout << "\nbfOffBits = " << pbfh->bfOffBits;

	char* tmp = (char*)&pbfh->bfType;
	cout << "\ntype[0] = " << tmp[0];
	cout << "\ntype[1] = " << tmp[1];

	cout << "\nBITMAPINFOHEADER";
	cout << "\nbiSize = " << pbih->biSize << "\n";

	fclose(fp);
	free(buff);

    return 0;
}

