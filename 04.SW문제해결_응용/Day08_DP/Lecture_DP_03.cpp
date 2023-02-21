// DP -  푸는방법이 2개
// #1. Top-Down : 재귀 구조
// #2. Bottom-Up(Tabulation) : 점화식 활용

// 피보나치 수열 - Bottom-Up
#include <iostream>
using namespace std;

int N;
int dp[101];

int main()
{
	// input
	cin >> N;

	// solve
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

	// output
	cout << dp[N];

	return 0;
}