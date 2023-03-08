#include <iostream>
using namespace std;

int numCnt;
int maxValue, minValue;
int num[11], calc[4];

void run(int level, int result)
{
	// #2. 기저 조건
	if (level == numCnt)
	{
		if (result > maxValue) maxValue = result;
		if (result < minValue) minValue = result;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// #4. 가지 치기
		if (calc[i] == 0) continue;

		// #3. 기록 및 처리
		calc[i] -= 1;

		// #1. 재귀 기본 구조
		if (i == 0) run(level + 1, result + num[level]);
		if (i == 1) run(level + 1, result - num[level]);
		if (i == 2) run(level + 1, result * num[level]);
		if (i == 3) run(level + 1, result / num[level]);

		// #5. 복구
		calc[i] += 1;		
	}
}

int main()
{
	// reset
	maxValue = -21e8;
	minValue = 21e8;

	// input
	cin >> numCnt;
	for (int i = 0; i < numCnt; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> calc[i];

	// solve
	run(1, num[0]);

	// output
	cout << maxValue << '\n' << minValue;

	return 0;
}