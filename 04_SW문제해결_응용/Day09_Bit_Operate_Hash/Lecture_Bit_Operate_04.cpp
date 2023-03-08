// bit masking #3
// 특정 비트를 바꾸는 방법 - A의 N번째 비트 지운다.

#include <iostream>
using namespace std;

int main()
{
	int A = 5; // 0101
	int N = 0; // 원하는 답 0100

	int result = A & ~(1 << N);
	cout << result;

	return 0;
}