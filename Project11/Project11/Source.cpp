#include "Header.h"

//セルの総数
#define WIDTH 27
#define HEIGHT 27

//セルのキャラ情報
unsigned char gTable[WIDTH][HEIGHT];

bool isLive(int x, int y)
{
	if (x < 0 || WIDTH <= x) return false;
	if (y < 0 || HEIGHT <= y) return false;

	if (gTable[y][x] == 1) return true;
	return false;
}

bool isLiveInNextGeneration(int x, int y)
{

	//上下左右を走査
	int left = x - 1;
	int up = y - 1;
	int right = x + 1;
	int down = y + 1;

	int liveCount = 0;
	if (isLive(left, up)) liveCount++;
	if (isLive(x, up)) liveCount++;
	if (isLive(right, up)) liveCount++;
	if (isLive(left, y)) liveCount++;
	if (isLive(right, y)) liveCount++;
	if (isLive(left, down)) liveCount++;
	if (isLive(x, down)) liveCount++;
	if (isLive(right, down)) liveCount++;

	if (isLive(x, y)) {
		// 現世代は生きている
		if (liveCount <= 1) return false; // 過疎により死
		if (liveCount == 2 || liveCount == 3) return true; // 生存
		if (4 <= liveCount) return false; // 過密により死
	}

	// 現世代は死んでいる
	if (liveCount == 3) return true;  // 誕生
	return false; //死のまま
}

int main()
{

}