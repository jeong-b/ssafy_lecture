/* input
1200 5
10 50 100 400 500
*/

// 동전 거슬러주기 - Bottom-Up
#include <iostream>
using namespace std;

int target, N;
int coins[10];
int dp[100001]; // index: 금액 value : 최소 동전 개수

int main()
{
	// input
	cin >> target >> N;
	for (int i = 0; i < N; i++) cin >> coins[i];

	// solve
	for (int i = 0; i <= target; i++) dp[i] = 21e8;
	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		int now = coins[i];
		for (int j = now; j < target; j++)
		{
			if (dp[j - now] + 1 < dp[j]) dp[j] = dp[j - now] + 1;
		}
	}

	// output
	cout << dp[target];	

	return 0;
}