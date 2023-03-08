#include <iostream>
using namespace std;

int N;
int calc[4];
int num[12];
int path[11];
int used[4];
int result, maxValue, minValue;

void run(int level)
{
	// 2. 기저 조건
	if (level == N - 1)
	{
		result = num[0];
		for (int i = 0; i < N - 1; i++)
		{
			if (path[i] == 1) result = result + num[i + 1];
			else if (path[i] == 2) result = result - num[i + 1];
			else if (path[i] == 3) result = result * num[i + 1];
			else if (path[i] == 4) result = result / num[i + 1];
		}

		if (result > maxValue) maxValue = result;
		if (result < minValue) minValue = result;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// 4. 가지치기
		if (used[i] == calc[i]) continue;

		// 3.기록 및 처리
		used[i] += 1;
		path[level] = i + 1;

		// 1. 재귀 기본 구조
		run(level + 1);

		// 5. 복구
		used[i] -= 1;
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
		for (int i = 0; i < 4; i++) calc[i] = 0;
		for (int i = 0; i < 12; i++) num[i] = 0;
		maxValue = -21e8;
		minValue = 21e8;

		// input
		cin >> N;
		for (int i = 0; i < 4; i++) cin >> calc[i];
		for (int i = 0; i < N; i++) cin >> num[i];
		
		
		// solve
		run(0);

		// output
		cout << "#" << tc << " " << maxValue - minValue << "\n";
	}

	return 0;
}