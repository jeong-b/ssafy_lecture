// bit masking #2
// 특정 비트를 바꾸는 방법 - A의 N번째 비트를 1이면 0으로, 0이면 1로 바꾼다

#include <iostream>
using namespace std;

int main()
{
	int A = 5; // 0101
	int N = 2; // 원하는 답 0001

	int result = A ^ (1 << N);
	cout << result;

	return 0;
}