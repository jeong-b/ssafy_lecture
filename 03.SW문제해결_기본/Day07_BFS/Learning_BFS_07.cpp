// BFS - Tree 구조(인접행렬)
#include <iostream>
#include <queue>
using namespace std;

int adj[5][5] = {
	0, 1, 0, 0, 1,
	0, 0, 1, 1, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0
};
char name[5] = { 'A', 'C', 'T', 'S', 'B' };
queue<int> q;

int main()
{
	q.push(0);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << name[now];

		for (int i = 0; i < 5; i++)
		{
			if (adj[now][i] == 0) continue;
			q.push(i);
		}
	}

	return 0;
}