// Project51.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "protre5_1parts.h"

int main()
{
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;

	char* p = (char*)&bfh.bfType;
	p[0] = 'B';
	p[1] = 'M';
	bfh.bfSize = 20864;
	bfh.bfOffBits = 262;
	bih.biSize = sizeof(BITMAPINFOHEADER);
	bih.biWidth = 200;
	bih.biHeight = 103;
	bih.biPlanes = 1;
	bih.biBitCount = 8;
	bih.biCompression = 0;
	bih.biSizeImage = 20602;
	bih.biXPelsPerMeter = 2834;
	bih.biYPelsPerMeter = 2834;
	bih.biClrUsed = 52;
	bih.biClrImportant = 52;


	FILE* fp;


	if ((fp = fopen("test.bmp", "wb")) == NULL)
	{
		cout << "ERROR:failed file opend";
		getchar();
		return -1;
	}

	if (1 != fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, fp))
	{
		cout << "ERROR:failed written file";
		getchar();
		fclose(fp);
		return -1;
	}

	if (1 != fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, fp))
	{
		cout << "ERROR:failed written file";
		getchar();
		fclose(fp);
		return -1;
	}

	if (1 != fwrite(palette, sizeof(palette), 1, fp))
	{
		cout << "ERROR:failed written file";
		getchar();
		fclose(fp);
		return -1;
	}

	if (1 != fwrite(image, sizeof(image), 1, fp))
	{
		cout << "ERROR:failed written file";
		getchar();
		fclose(fp);
		return -1;
	}

	cout << "Completed:output of test.bmp";
	getchar();
	fclose(fp);

	return 0;
}

