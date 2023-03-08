#include <iostream>
#include <string>
using namespace std;

int N;
int map[16][16];
int path[8];
int used[16];
int limit, sumA, sumB, result, minValue;

void run(int level, int start)
{
	// 2. 기저 조건
	if (level == limit)
	{
		int y = 0, x = 0;
		sumA = 0;
		sumB = 0;
		for (int i = 0; i < N; i++)
		{
			if (path[y] == i)
			{
				x = 0;
				for (int j = 0; j < N; j++)
				{
					if (path[x] == j)
					{
						sumA += map[i][j];
						x++;
					}
				}
				y++;
			}
			else
			{	
				x = 0;
				for (int j = 0; j < N; j++)
				{
					if (path[x] == j) x++;
					else sumB += map[i][j];	
				}
			}
		}

		if (sumA >= sumB) result = sumA - sumB;
		else result = sumB - sumA;

		if (result < minValue) minValue = result;

		return;
	}

	for (int i = start; i < N; i++)
	{
		// 4. 가지치기
		if (used[i] == 1) continue;


		// 3. 기록 및 처리
		used[i] = 1;
		path[level] = i;

		// 1. 재귀 기본 구조
		run(level + 1, i + 1);

		// 5. 복구
		used[i] = 0;
		path[level] = 0;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		// reset
		memset(map, 0, sizeof(map));
		memset(path, 0, sizeof(path));
		memset(used, 0, sizeof(used));
		minValue = 21e8;

		// input
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		limit = N / 2;

		// solve
		path[0] = 0;
		used[0] = 0;
		run(1, 1);

		// output
		cout << "#" << tc << " " << minValue << "\n";
	}

	return 0;
}