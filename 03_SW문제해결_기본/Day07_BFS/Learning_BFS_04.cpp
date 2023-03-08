// DFS와 비교
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int used[10];
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

void dfs(int now)
{
	cout << now << " ";
	for (int i = 0; i < map[now].size(); i++)
	{
		int to = map[now][i];

		if (used[to] == 1) continue;

		used[to] = 1;
		dfs(to);
	}
}

int main()
{
	input();

	used[0] = 1;
	dfs(0);

	return 0;
}