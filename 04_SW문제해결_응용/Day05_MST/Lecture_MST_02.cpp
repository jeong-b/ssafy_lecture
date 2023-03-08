/* input_1
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 1

output_1 : -1
*/

/* input_2
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 35

output_1 : 135
*/

// MST 활용 - 특정간선 제외 및 미완성 학인
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int a, b, cost;
};

bool cmp(Node left, Node right)
{
	if (left.cost < right.cost) return true;
	if (left.cost > right.cost) return false;

	return false;
}

int nodeCnt, edgeCnt;
int parent[10];
vector<Node> alist;

int Find(int now)
{
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int A, int B)
{
	int pA = Find(A);
	int pB = Find(B);

	if (pA == pB) return;

	parent[pA] = pB;
}

int kruskal()
{
	// 간선의 비용이이 적은 순으로 정렬
	sort(alist.begin(), alist.end(), cmp);

	// MST의 간선으로 채택이 가능한지 확인
	int sumCost = 0;
	int cnt = 0;
	for (int i = 0; i < alist.size(); i++)
	{
		Node now = alist[i];

		if (now.cost < 10) continue;
		if (Find(now.a) == Find(now.b)) continue;

		sumCost += now.cost;
		cnt++;

		Union(now.a, now.b);
	}

	if (cnt != nodeCnt - 1) return -1;
	return sumCost;
}

int main()
{
	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		alist.push_back({ from, to, cost });
	}

	// solve & output
	for (int i = 0; i < nodeCnt; i++) parent[i] = i;

	cout << kruskal();

	return 0;
}