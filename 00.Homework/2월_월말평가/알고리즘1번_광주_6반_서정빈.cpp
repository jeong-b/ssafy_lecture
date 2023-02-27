#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodeCnt, edgeCnt;
int cnt;
int used[101];
vector<vector<int>> alist;

void bfs(int start)
{
	// queue
	queue<int> q;
	q.push(start);

	// used
	used[start] = cnt;

	// bfs
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < alist[now].size(); i++)
		{
			int next = alist[now][i];

			if (used[next] != 0) continue;

			used[next] = cnt;
			q.push(next);
		}
	}
}

int main()
{
	// reset
	for (int i = 0; i < 101; i++) used[i] = 0;
	cnt = 0;

	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i <= nodeCnt; i++) alist.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}

	// solve
	for (int i = 1; i <= nodeCnt; i++)
	{
		if (used[i] != 0) continue;

		cnt++;
		used[i] = cnt;

		bfs(i);
	}

	// output
	cout << cnt;

	return 0;
}