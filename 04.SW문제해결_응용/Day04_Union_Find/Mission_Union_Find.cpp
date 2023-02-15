/* input
6 5
10 20 30 40 50 60
0 1
3 0
3 4
4 3
2 5

// output : 10 10 40 60 40 50
*/

// 문제
// N개의 회사사 있습니다
// 회사들이 M개의 인수합병을 진행 합니다.
// A가 B를 인수할 때 A회사가 대표회사가 되고,
// B의 개발자 10명이 A회사로 이직합니다.
// M개의 인수 합병 이후, 각 회사의 소속된 개발자 수 출력
// input : N, M -> 개발자 수 -> 인수 합병 관계
#include <iostream>
using namespace std;

int nodeCnt, edgeCnt;
int employees[10];
int parents[10];

int findParent(int now)
{
	if (parents[now] == now) return now;

	return parents[now] = findParent(parents[now]);
}

void unionCompany(int a, int b)
{
	int pA = findParent(a);
	int pB = findParent(b);

	if (pA == pB) return;

	parents[pB] = pA;

	if (employees[pA] < 0 || employees[pB] < 0) return;
	employees[pA] += 10;
	employees[pB] -= 10;
}

int main()
{
	// reset
	for (int i = 0; i < 10; i++) parents[i] = i;

	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) cin >> employees[i];
	for (int i = 0; i < edgeCnt; i++)
	{
		int A, B;
		cin >> A >> B;
		unionCompany(A, B);
	}

	// output
	for (int i = 0; i < nodeCnt; i++) cout << employees[i] << " ";	

	return 0;
}