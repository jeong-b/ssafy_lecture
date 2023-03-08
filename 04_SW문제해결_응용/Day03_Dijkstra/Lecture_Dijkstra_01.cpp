// Dijkstra Algorithm : 최단거리 알고리즘
// #1. 가중치가 없는 그래프의 최단 경로 : BFS
// #2. 가중치가 없는 그래프이 최단 거리 : Dijkstra
// * Belman-Ford : 음수 가중치
// 
// Dijkstra : 가중치가 가장 작은 것 위주로 골라서 간다
// 출발 -> 모든 노드 최단거리 : 거리를 담당하는 DAT - dist
// 
// 기본 방법
// 준비단계
// #1. dist DAT 필요 -> dist 모든 값에 최대값 체운 후, dist[출발지] = 0
// #2. visted 필요 - 지금 이 노드의 최단 거리가 확정 되었는가?
// 
// 구현 단계/
// #1. 모든 노드의 최단 거리가 확정 될 때 까지
// #2. 지금 dist에 기록 되어있는 후보거리 중 가장 작은 간선을 가진 노드를 찾는다
// #3. now번 노드로부터 갈 수 있는 모든 간선을 확인하며 dist의 후보지 갱신
// 
// priority queue 사용 방법
// 준비단계
// #1. priority queue 준비 -> 시작 Edde를 일단 삽입 (시작노드, 0)
// #2. dist DAT 필요 -> dist 모든 값에 최대값 체운 후, dist[출발지] = 0
// #3. visted 필요 - 지금 이 노드의 최단 거리가 확정 되었는가?
// 
// 구현 단계
// #1. 더 이상 갈 후보지가 없을 때 까지
// #2. 가장 가중치가 작은 간선 체택 -> (top) = now
// #3. now로부터 갈 수 있는 간선을 확인하면서 dist 기록갱신 -> PQ에 후보지 삽입
//

/* input
10 13
0 1 1
0 3 4
0 2 5
1 4 3
1 5 6
2 5 8
2 7 10
2 6 9
7 6 11
6 9 2
6 8 13
7 8 12
5 6 7
*/

/* Dijkstra 구현 하기 - 인접 리스트 활용 :  시간복잡도 O(V^2)
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
	int to;
	int cost;
};

int nodeCnt, edgeCnt;
vector<Edge> alist[20];

void dijkstra(int start)
{
	// dist wnsql
	int dist[10] = { 0 };
	int maxValue = 21e8;
	for (int i = 0; i < nodeCnt; i++)
	{
		dist[i] = maxValue;
	}
	dist[start] = 0;		

	// visted 준비
	int visited[10] = { 0 };

	// dijkstra 구현
	for (int i = 0; i < nodeCnt; i++)
	{
		int minCost = 21e8;
		int now = -1;

		for (int j = 0; j < nodeCnt; j++)
		{
			if (dist[j] >= minCost) continue;
			if (visited[j] == 1) continue;

			minCost = dist[j];
			now = j;
		}

		// now까지의 최단 거리 = 확정
		visited[now] = 1;

		for (int j = 0; j < alist[now].size(); j++) {
			Edge next = alist[now][j];
			
			int ncost = dist[now] + next.cost;
			 
			if (dist[next.to] <= ncost)	continue;

			dist[next.to] = ncost;
		}
	}

	// output
	for (int i = 0; i < nodeCnt; i++) cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';	
}

int main()
{
	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		alist[from].push_back({ to, cost });
		alist[to].push_back({ from, cost });
	}

	// solve
	dijkstra(0);

	return 0;
}
*/

/* Dijkstra 구현 하기 + PQ 활용 하기 - 인접 리스트 활용 : 시간복잡도 O(ElogE)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int to;
	int cost;

	bool operator < (Edge next) const
	{
		if (cost < next.cost) return false;
		if (cost > next.cost) return true;

		return false;
	}
};

int nodeCnt, edgeCnt;
vector<Edge> alist[20];

void dijkstra(int start)
{
	// 준비 단계
	// #1. priority queue
	priority_queue<Edge> pq;
	pq.push({ start , 0 });

	// #2. dist
	int dist[10] = { 0 };
	int maxValue = 21e8;
	for (int i = 0; i < nodeCnt; i++) dist[i] = maxValue;
	dist[start] = 0;

	// #3. visted
	int visited[10] = { 0 };

	// 구현단계
	// #1. 더이상 갈 후보지 가 없을때까지 반복
	while (!pq.empty())
	{
		// #2. 후보지 중 가장 낮은 가중치의 간선을 선택
		Edge now = pq.top();
		pq.pop();

		if (visited[now.to] == 1) continue;
		visited[now.to] = 1;

		// #3. now로 부터 갈 수 있는 간선 확인
		for (int i = 0; i < alist[now.to].size(); i++)
		{
			Edge next = alist[now.to][i];
			int ncost = dist[now.to] + next.cost;

			if (dist[next.to] <= ncost) continue;

			dist[next.to] = ncost;
			pq.push({ next.to, ncost });
		}
	}

	// output
	for (int i = 0; i < nodeCnt; i++) cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';	
}

int main()
{
	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		alist[from].push_back({ to, cost });
		alist[to].push_back({ from, cost });
	}

	// solve
	dijkstra(0);
}
*/

/* Dijkstra 구현 하기 + PQ 활용 하기 + visited 안쓰기 - 인접 리스트 활용
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int to;
	int cost;

	bool operator < (Edge next) const
	{
		if (cost < next.cost) return false;
		if (cost > next.cost) return true;

		return false;
	}
};

int nodeCnt, edgeCnt;
vector<Edge> alist[20];

void dijkstra(int start)
{
	// 준비 단계
	// #1. priority queue
	priority_queue<Edge> pq;
	pq.push({ start , 0 });

	// #2. dist
	int dist[10] = { 0 };
	int maxValue = 21e8;
	for (int i = 0; i < nodeCnt; i++) dist[i] = maxValue;
	dist[start] = 0;

	// 구현단계
	// #1. 더이상 갈 후보지 가 없을때까지 반복
	while (!pq.empty())
	{
		// #2. 후보지 중 가장 낮은 가중치의 간선을 선택
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost) continue;
		

		// #3. now로 부터 갈 수 있는 간선 확인
		for (int i = 0; i < alist[now.to].size(); i++)
		{
			Edge next = alist[now.to][i];
			int ncost = dist[now.to] + next.cost;

			if (dist[next.to] <= ncost) continue;

			dist[next.to] = ncost;
			pq.push({ next.to, ncost });
		}
	}

	// output
	for (int i = 0; i < nodeCnt; i++) cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
}

int main()
{
	// input
	cin >> nodeCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		alist[from].push_back({ to, cost });
		alist[to].push_back({ from, cost });
	}

	// solve
	dijkstra(0);
}
*/