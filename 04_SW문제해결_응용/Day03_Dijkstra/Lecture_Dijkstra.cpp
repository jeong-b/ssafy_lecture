/* input
1 2 60
1 3 50
1 5 40
2 7 10
3 4 10
4 2 20
4 6 50
5 2 10
5 7 10
6 2 10
7 6 10
*/

/* dfs 로 모든 경로 탐색
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node; 
	int cost; 
};
int N, T; 
vector<Edge> adj[8]; 
void input() {
	cin >> N >> T; 
	for (int i = 0; i < T; i++)
	{
		int a, b, cost; 
		cin >> a >> b >> cost; 
		adj[a].push_back({ b,cost });
	}
}
int cnt = 0; 
int visited[8]; // 경로상에 중복 등장하지 않도록 막기
void dfs(int now,int accSum,string path)
{
	if (now == 6) { // 1 ~~~~>6
		cnt++;
		cout << "경로 발견!" << accSum << " " << path << "\n";
		return; 
	}
	for (Edge next : adj[now])
	{
		if (visited[next.node] == 1) continue; 
		visited[next.node] = 1; // 이후 경로에서 등장 x 
		dfs(next.node, accSum + next.cost, path + to_string(next.node) + "->"); // 1 ~~~~>
		visited[next.node] = 0;
	}
}
int main() {
	input(); 
	visited[1] = 1; // 1번지점은 이후에 다시 등장 안한다.
	dfs(1,0,"1->");
	cout << cnt; 
	return 0;
}
*/

/* dijkstra 연습
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int to;
	int cost;

	bool operator < (Edge next) const { return cost > next.cost; }
};

int nodeCnt, edgeCnt;
int dist[10];
int maxValue = 21e8;
vector<Edge> alist[10];
priority_queue<Edge> pq;

void dijkstra(int start)
{
	// 1. priority_queue 준비
	pq.push({ start, 0 });

	// 2. dist 준비
	for (int i = 1; i <= nodeCnt; i++) dist[i] = maxValue;
	dist[start] = 0;

	// 3. 실행
	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost) continue;

		for (int i = 0; i < alist[now.to].size(); i++)
		{
			Edge next = alist[now.to][i];
			int ncost = dist[now.to] + next.cost;

			if (dist[next.to] <= ncost) continue;

			dist[next.to] = ncost;
			pq.push({ next.to, ncost });
		}
	}

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
	}

	// solve
	int start, finish;
	cin >> start >> finish;
	dijkstra(start);

	// output
	cout << start << " 부터 " << finish << " 까지 최소 비용은 " << dist[finish] << "입니다.\n";


	return 0;
}
*/

/* 가짜 dijkstra 
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node;
	int cost;
};
struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용 
};
struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost;
	}
};
int N, T;
vector<Edge> adj[8];
void input() {
	cin >> N >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ b,cost });
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	// 가짜 dijkstra 
	priority_queue<Node, vector<Node>, cmp> pq;
	int processed[8] = { 0 };
	int start = 1;
	pq.push({ start, 0 }); // start, start~~>start비용
	int dist[8] = { 0 };
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop();
		if (processed[now.node] == 1)continue;
		processed[now.node] = 1;
		dist[now.node] = now.accCost;
		// proccess 
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
			pq.push({ next.node, newCost });
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
	}
	return 0;
}
*/

/* 다익스트라 코드
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node;
	int cost;
};
struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용
};
struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost;
	}
};
int N, T;
vector<Edge> adj[8];
void input() {
	cin >> N >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ b,cost });
	}
}
const int INF = 1e9; // 10억
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	priority_queue<Node, vector<Node>, cmp> pq;
	int dist[8];  // dist[A] : PQ에 있는 A의 제일 작은 누적비용
	for (int i = 1; i <= 7; i++) dist[i] = INF;
	int processed[8] = { 0 };
	int start = 1;
	pq.push({ start, 0}); // start, start~~>start비용
	dist[start] = 0;
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop();
		if (processed[now.node] == 1)continue;
		processed[now.node] = 1;
		// proccess
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
			if (newCost < dist[next.node])
			{
				dist[next.node] = newCost;
				pq.push({ next.node, dist[next.node]});
			}
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
	}

	return 0;
}
*/

/* 다익스트라 코드
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node;
	int cost;
};
struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용
};
struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost;
	}
};
int N, T;
vector<Edge> adj[8];
void input() {
	cin >> N >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ b,cost });
	}
}
const int INF = 1e9; // 10억
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	priority_queue<Node, vector<Node>, cmp> pq;
	int dist[8];  // dist[A] : PQ에 있는 A의 제일 작은 누적비용
	for (int i = 1; i <= 7; i++) dist[i] = INF;
	int start = 1;
	pq.push({ start, 0}); // start, start~~>start비용
	dist[start] = 0;
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop();
		if (now.accCost > dist[now.node])continue;
		// proccess
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
			if (newCost < dist[next.node])
			{
				dist[next.node] = newCost;
				pq.push({ next.node, dist[next.node]});
			}
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl;
	}

	return 0;
}

*/