// BFS 활용 - used에 경로의 거리를 기록 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) map.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	int used[10] = { 0 };
	used[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i];

			if (used[next] != 0) continue;

			used[next] = used[now] + 1;
			q.push(next);
		}
	}

	cout << "\n";

	for (int i = 0; i < 4; i++)
	{
		cout << used[i] - 1 << " ";
	}
}

int main()
{
	input();

	bfs(0);	

	return 0;
}