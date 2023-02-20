#include <iostream>
using namespace std;

int N, K;
int map[100][100];
int sum;
int result = -21e8;

void run(int y, int x, int level)
{
	// #2. 기저조건
	if (level > K)
	{
		if (sum > result) result = sum;
		sum = 0;
		return;
	}

	// #3. 기록 및 처리
	int dir[4][2] = { {-1, 1}, {1, -1}, {-1, -1}, {1, 1} };
	for (int i = 0; i < 4; i++)
	{
		int ny = y + (dir[i][0] * level);
		int nx = x + (dir[i][1] * level);

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

		sum += map[ny][nx];
	}

	// #1. 재귀 기본 구조
	run(y, x, level + 1);
}

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> K;

	// solve
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			run(i, j, 1);
		}
	}

	// output
	cout << result;

	return 0;
}