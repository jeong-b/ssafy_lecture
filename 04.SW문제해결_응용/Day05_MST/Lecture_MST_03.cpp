/* input
5 8
0 1 50
0 2 30
1 2 5
1 3 7
2 4 20
2 3 8
1 4 9
3 4 35
*/

// MST 할용
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to, cost;
	
	bool operator < (Edge next) const {
		if (cost < next.cost) return false;
		if (cost > next.cost) return true;
		return false;
	}
};

int N, M;
vector<Edge>al[101];

int prim(int start) {
	// #1. priority queue 준비
	priority_queue<Edge>pq;
	pq.push({ start, 0 });

	// #2. connected DAT를 준비 
	int connected[101] = { 0, };

	// 비용 초기화
	int sum = 0;
	int cnt = 0;
	// prim 동작
	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (connected[now.to] == 1)	continue;
		
		connected[now.to] = 1;		
		sum += now.cost;
		cnt++;
				
		for (int i = 0; i < al[now.to].size(); i++)
		{
			Edge next = al[now.to][i];
			
			if (connected[next.to] == 1) continue;

			pq.push(next);
		}
	}
	if (cnt == N) return sum;
	return -1;
}

int main()
{
	// input
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		al[from].push_back({ to, cost });
		al[to].push_back({ from, cost });
	}

	// solve
	cout << prim(2);
}