/* input
9 7
0 3
3 6
6 8
3 7
1 4
2 5
0 1
*/

// Union - 결합하기
#include <iostream>
using namespace std;

int nodeCnt, edgeCnt;
int parents[10];

int Find(int now)
{
	// 종료 조건
	if (parents[now] == now) return now;

	// 재귀 구성 - path compression
	return parents[now] = Find(parents[now]);
}

void Union(int A, int B)
{
	// #1. A와 B의 소속 확인
	int pA = Find(A);
	int pB = Find(B);

	// #2. B의 소속을 A소속 산하로 만든다
	parents[pB] = pA;
}

int main()
{
	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) parents[i] = i;
	for (int i = 0; i < edgeCnt; i++)
	{
		int child, parent;
		cin >> child >> parent;
		Union(child, parent);
	}

	int a, b;
	cin >> a >> b;
	// a와 b는 같은 그룹인가?

	if (Find(a) == Find(b)) cout << "같은 그룹";
	else cout << "다른 그룹";

	return 0;
}