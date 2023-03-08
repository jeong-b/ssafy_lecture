// 피보나치 수열 DP 활용하기 - Top-Down
#include <iostream>
using namespace std;

int N;
int dp[101];

int fibo(int now)
{
	// #2. 기저 조건
	if (now <= 2) return 1;

	// #3. 기록되어 있다면 재귀를 돌지 않고 바로 값을 가져오기
	if (dp[now] != 0) return dp[now];

	// #1. 재귀 기본 구조 - 리턴값을 dp에 기록
	return dp[now] = fibo(now - 1) + fibo(now - 2);
}

int main()
{
	// input
	cin >> N;

	// solve & output
	cout << fibo(N);

	return 0;
}