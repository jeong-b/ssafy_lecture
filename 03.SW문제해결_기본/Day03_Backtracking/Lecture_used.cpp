/* 주사위 게임 - N개의 주사위를 던져 나오는 경우의 수 중 중복을 허용하지 않는 모든 경우 */
#include <iostream>
using namespace std;

int path[3]; // 재귀의 지나온 경로를 기록
int used[7]; // DAT 활용 - index : 주사위 눈, value : 사용 여부(0 : 미사용 / 1 : 사용)
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
    // 4. 가지 치기
    if (used[i] == 1) continue;
    // 3. 기록 및 처리
		path[level] = i;
    used[i] = 1;
    // 1. 재귀 기본 구조
		run(level + 1);
    // 5. 복구
    used[i] = 0;
	}
}

int main()
{
  cin >> N;
	run(0);
	return 0;
}