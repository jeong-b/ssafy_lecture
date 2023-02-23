// 입접 리스트 활용한 BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodeCnt, edgeCnt;
vector<vector<int>> map;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) map.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << " ";
		
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i];			
			q.push(next);
		}
	}
}

int main()
{
	input();

	bfs(0);

	return 0;
}