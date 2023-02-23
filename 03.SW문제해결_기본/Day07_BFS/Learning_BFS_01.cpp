// 인접 행렬 활용한 BFS
#include <iostream>
#include <queue>
using namespace std;

int nodeCnt, edgeCnt;
int map[10][10];

void bfs(int start)
{
	// 1. queue 준비
	queue<int> q;
	// queue에 시작 노드 삽입
	q.push(start);

	while (!q.empty())
	{
		// 2. queue의 맨 앞의 노드를 방문
		int now = q.front(); // now : 지금 방문하는 노드
		// queue에서 삭제
		q.pop();

		cout << now << " ";

		// 3. 갈 수 있는 노드를 판단하고 -> queue에 삽입
		for (int next = 0; next < nodeCnt; next++)
		{
			if (map[now][next] == 0) continue;
			q.push(next);
		}
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
	}

	bfs(0);

	return 0;
}