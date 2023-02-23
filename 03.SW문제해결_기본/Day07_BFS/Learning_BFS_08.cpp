// BFS - Tree 구조(인접리스트)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> alist;
queue<int> q;
char name[5] = { 'A', 'C', 'T', 'S', 'B' };
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) alist.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
	}
}


int main()
{
	input();

	q.push(0);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << name[now];

		for (int i = 0; i < alist[now].size(); i++) q.push(alist[now][i]);		
	}

	return 0;
}