#include "stdafx.h"

using namespace std;

//ヘッダを設計
struct PROTRE6_HEADER
{
	char fname1[64];
	int fsize1;
	int foffset1;

	char fname2[64];
	int fsize2;
	int foffset2;
};

int main()
{

	//ヘッダサイズを取得
	int header_size = sizeof(PROTRE6_HEADER);

	//ファイル1のサイズを取得
	FILE* fp1;
	if ((fp1 = fopen("file1.bmp", "rb")) == NULL)
	{
		cout << "ERROR:failed file opend\n";
		getchar();
		return -1;
	}
	fseek(fp1, 0, SEEK_END);
	int fsize1 = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);

	//ファイル2のサイズを取得
	FILE* fp2;
	if ((fp2 = fopen("file2.png", "rb")) == NULL)
	{
		cout << "ERROR:failed file opend\n";
		getchar();
		return -2;
	}
	fseek(fp2, 0, SEEK_END);
	int fsize2 = ftell(fp2);
	fseek(fp2, 0, SEEK_SET);

	//アラインメントの取得
	int fsize1_adjust = ((fsize1 / 8) + (0 != (fsize1 % 8))) * 8;
	int fsize2_adjust = ((fsize2 / 8) + (0 != (fsize2 % 8))) * 8;

	//合計のサイズを定義
	int all_size = header_size + fsize1_adjust + fsize2_adjust;
	unsigned char* buff;
	if ((buff = (unsigned char*)malloc(all_size)) == NULL)
	{
		cout << "ERROR:failed alloced\n";
		fclose(fp1);
		fclose(fp2);
		getchar();
		return -3;
	}

	//メモリの先頭にヘッダ構造体のポインタを当てる
	PROTRE6_HEADER* pHeader = (PROTRE6_HEADER*)buff;

	//ファイル1とファイル2の名前を確保
	strcpy(pHeader->fname1, "file1.bmp");
	strcpy(pHeader->fname2, "file2.png");

	//二つのファイルサイズを格納
	pHeader->fsize1 = fsize1;
	pHeader->fsize2 = fsize2;

	//ファイル1・ファイル2の書き込み位置を確保
	pHeader->foffset1 = sizeof(PROTRE6_HEADER);
	pHeader->foffset2 = pHeader->foffset1 + fsize1_adjust;

	unsigned char* fptr1 = (unsigned char*)(buff + pHeader->foffset1);
	unsigned char* fptr2 = (unsigned char*)(buff + pHeader->foffset2);

	//それぞれのファイルを読み込み
	if (1 != fread(fptr1, fsize1, 1, fp1))
	{
		cout << "ERROR:failed file read\n";
		fclose(fp1);
		fclose(fp2);
		free(buff);
		getchar();
		return -4;
	}

	if (1 != fread(fptr2, fsize2, 1, fp2))
	{
		cout << "ERROR:failed file read\n";
		fclose(fp1);
		fclose(fp2);
		free(buff);
		getchar();
		return -5;
	}

	//ファイルを閉じる
	fclose(fp1);
	fclose(fp2);

	FILE* fp3;
	if ((fp3 = fopen("test.pack", "wb")) == NULL)
	{
		cout << "ERROR:failed file opend\n";
		free(buff);
		getchar();
		return -6;
	}

	if (1 != fwrite(buff, all_size, 1, fp3))
	{
		cout << "ERROR:failed file written\n";
		free(buff);
		getchar();
		return -7;
	}

	cout << "Complet:file packing\n";
	fclose(fp3);
	free(buff);

	getchar();

	return 0;
}