// BFS 응용 -  가중리스트와 구조체 활용
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int nodeIndex;
	int price;
};

vector<vector<Node>> alist;
vector<int> path;
int used[4];
int nodeCnt, edgeCnt;

void input()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < nodeCnt; i++) alist.push_back({});
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, price;
		cin >> from >> to >> price;
		Node info;
		info.nodeIndex = to;
		info.price = price;
		alist[from].push_back(info);
	}
}

void dfs(int now, int sum)
{
	if (now == 3)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << sum <<  "\n";
		return;
	}

	for (int i = 0; i < alist[now].size(); i++)
	{
		Node next = alist[now][i];

		if (used[next.nodeIndex] == 1) continue;

		used[next.nodeIndex] = 1;
		path.push_back(next.nodeIndex);

		dfs(next.nodeIndex, sum + next.price);

		used[next.nodeIndex] = 0;
		path.pop_back();
	}
}

int main()
{
	input();
	used[0] = 1;
	path.push_back(0);
	dfs(0, 0);

	return 0;
}