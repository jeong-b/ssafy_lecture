// Union Find (Disjoint Set) : 소속/그룹을 만들고 유지/관리하는 알고리즘
// union : 서로 다른 두개의 집합을 결합하는 작업
// Find : 특정 소속에 속한 멤버가  어떤 소속에 포함되어 있는지 찾아가고 판단하는 작업
//

/* input
18 15
3 0
6 3 
9 6
10 6
11 6
4 1
7 4
12 7
13 7
14 7
5 2
8 5
15 8
16 8
17 8
*/

// Find : 소속을 찾아가는 작업 - 시간복잡도 O(N)
#include <iostream>
using namespace std;

int nodeCnt, edgeCnt;
int parents[20];
int target;

int find(int now)
{
	// 종료 조건
	if (parents[now] == now) return now;

	// 재귀 구성
	return find(parents[now]);
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
		parents[child] = parent;
	}
	cin >> target;

	// output
	cout << target << "의 소속은 " << find(target);


	return 0;
}