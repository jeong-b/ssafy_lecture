Find + 최적화 -> Path Compresson(경로 압축) - 경로압축 후 시간복잡도 O(A(N))
// 장점 : 시간 효율성 대폭 상승
// 단점 : 돌이킬 수 없음
#include <iostream>
using namespace std;

int parents[101];

int find(int now)
{
	// 종료 조건
	if (parents[now] == now) return now;

	cout << now << "의 부모 " << parents[now] << "\n";	

	// 재귀 구성
	// path compression
	return parents[now] = find(parents[now]);
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		parents[i + 1] = i;
	}

	find(100);

	cout << "==========\n";
	cout << "100 의 부모 " << parents[100] << "\n";

	return 0;
}