// DP : Dynamic Programming - 답을 기억하는 프로그래밍 기법
 
// 피보나치 수열의 기본 재귀 형태 : 숫자가 커질수록 반복적인 처리를 해서 시간이 오래 걸림
#include <iostream>
using namespace std;

int N;

int fibo(int now)
{
	// #2. 기저 조건
	if (now <= 2) return 1;

	// #1. 재귀 기본 구조 
	return fibo(now - 1) + fibo(now - 2);
}

int main()
{
	// input
	cin >> N;

	// solve & output
	cout << fibo(N);

	return 0;
}