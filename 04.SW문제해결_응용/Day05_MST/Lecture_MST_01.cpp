/* input
10 16
0 3 10
0 2 20
1 2 30
1 5 12
2 3 34
2 5 56
2 7 45
3 4 60
4 7 35
5 6 21
5 8 7
6 7 67
6 8 23
6 9 78
7 9 22
8 9 15
*/

// MST
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
	sort(alist.begin(), alist.end(), cmp);

	int sumCost = 0;
	for (int i = 0; i < alist.size(); i++)
	{
		Node now = alist[i];

		if (Find(now.a) == Find(now.b)) continue;

		sumCost += now.cost;

		Union(now.a, now.b);
	}

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