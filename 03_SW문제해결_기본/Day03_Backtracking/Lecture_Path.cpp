/* 주사위 게임 - N개의 주사위를 던져 나오는 모든 경우의 수 */
#include <iostream>
using namespace std;

int path[3]; // 재귀의 지가농 경로를 기록
int N;

void run(int level)
{
  // 2. 기저 조건
	if (level == N)
	{
    for (int i = 0; i < N; i++)
    {
      cout << path[i] << " ";
    }
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
    // 3. 기록 및 처리
		path[level] = i;
    // 1. 재귀 기본 구조
		run(level + 1);
	}
}

int main()
{
  cin >> N;
	run(0);
	return 0;
}