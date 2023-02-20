// Greedy : 탐욕 알고리즘
// Greedy로 풀 수 있는지 확인하는 방법
// #1. Greedy Choice Property
// #2. Optimal Substructure
// Greedy로 풀 수 있는지 확인하는 실용적인 방법
// S.V.I.P : Selection(선택) - 기준 -> Validation(검증) -> Implementation(구현) -> Pray(기도)
// 오답이 나오면 1. 기준 변경 2. Greedy 성립하지 않음 -> 다른 접근 필요 

/* input
1200 4
100 50 10 500
*/

/* Greedy - 거스름돈 예시
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int left, int right)
{
	if (left > right) return true;
	if (left < right) return false;

	return false;
}

int target, N;
int coins[5];

int main()
{
	// input
	cin >> target >> N;
	for (int i = 0; i < N; i++) cin >> coins[i];

	// S : 큰 동전부터 돌려주는 방법
	sort(coins, coins + N, cmp);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int now = coins[i];
		ans += target / now;
		target %= now;
	}
	cout << ans;

	return 0;
}