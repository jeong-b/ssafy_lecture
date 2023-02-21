/* input
1200 5
10 50 100 400 500
*/

// 동전 거슬러주기 - Top-Down
#include <iostream>
using namespace std;

int target, N;
int coins[10];
int dp[100001]; // index: 금액 value : 최소 동전 개수

int func(int now)
{
	// #2 .기저 조건
	if (now == 0) return 0;
	if (now < 0) return 21e8;

	// #3. 기록되어 있다면 재귀를 돌지 않고 바로 값을 가져오기
	if (dp[now] != 0) return dp[now];

	// #1. 재귀 구성
	int MIN = 21e8;
	for (int i = 0; i < N; i++)
	{
		int temp = func(now - coins[i]) + 1;
		if (temp < MIN) MIN = temp;
	}
	return dp[now] = MIN;
}

int main()
{
	// input
	cin >> target >> N;
	for (int i = 0; i < N; i++) cin >> coins[i];

	// solve & output
	cout << func(target);
	

	return 0;
}