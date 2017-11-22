#include "stdafx.h"

using namespace std;

struct PROTRE6_HEADER
{
	char fname1[64];
	int fsize1;
	int foffset1;

	char fname2[64];
	int fsize2;
	int foffset2;
};

int thawing()
{
	//ファイルを開く
	FILE* fp3;
	if ((fp3 = fopen("test.pack", "rb")) == NULL)
	{
		cout << "ERROR:failed file opend\n";
		getchar();
		return -1;
	}

	//メモリへ読み込む
	fseek(fp3, 0, SEEK_END);
	int size = ftell(fp3);
	fseek(fp3, 0, SEEK_SET);

	unsigned char* buff;
	if ((buff = (unsigned char*)malloc(size)) == NULL)
	{
		cout << "ERROR:failed alloced\n";
		fclose(fp3);
		return -2;
	}
	if ((1 != fread(buff, size, 1, fp3)) == NULL)
	{
		cout << "ERROR:failed file read\n";
		fclose(fp3);
		free(buff);
		getchar();
		return -3;
	}

	//閉じる
	fclose(fp3);

	//ヘッダーをあてる
	PROTRE6_HEADER* pHeader = (PROTRE6_HEADER*)buff;

	//ファイル1へファイルを書き出す
	FILE* fp1 = fopen(pHeader->fname1, "wb");
	unsigned char* fptr1 = (unsigned char*)(buff + pHeader->foffset1);
	if (1 != fwrite(fptr1, pHeader->fsize1, 1, fp1))
	{
		cout << "ERROR:failed file written\n";
		fclose(fp1);
		free(buff);
		getchar();
		return -4;
	}
	fclose(fp1);

	//ファイル2へファイルを書き出す
	FILE* fp2 = fopen(pHeader->fname2, "wb");
	unsigned char* fptr2 = (unsigned char*)(buff + pHeader->foffset2);
	if (1 != fwrite(fptr2, pHeader->fsize2, 1, fp2))
	{
		cout << "ERROR:failed file written\n";
		fclose(fp2);
		free(buff);
		getchar();
		return -5;
	}
	fclose(fp2);

	return 0;
}