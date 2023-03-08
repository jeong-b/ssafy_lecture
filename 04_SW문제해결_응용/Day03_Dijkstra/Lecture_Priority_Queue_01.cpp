/* mincoding : level.34 - #6.금 나와라 황금 보자자기
#include <iostream>
#include <queue>
using namespace std;

struct Item
{
	int weight;
	bool isGold;

	bool operator < (Item next) const
	{
		if (weight < next.weight) return false;
		if (weight > next.weight) return true;

		if (isGold == true && next.isGold == false) return false;
		if (isGold == false && next.isGold == true) return false;

		return false;
	}
};

int N;
priority_queue<Item> pq;

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int weight;
		cin >> weight;
		pq.push({ weight, true });
	}

	// solve
	int cnt = 0;
	while (true)
	{
		Item first = pq.top();
		pq.pop();
		if (first.isGold == false) break;
		cnt++;

		Item second = pq.top();
		pq.pop();
		if (second.isGold == false) break;
		cnt++;

		pq.push({ 2 * second.weight, false });
	}

	// output
	cout << cnt;

	return 0;
}
*/

/* mincoding - Level.35 #3. 연쇄 폭탄
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int time;
	int row;
	int col;
};

struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.time > right.time;		
	}
};

int N;
int answer;
int map[1000][1000];
int isBombed[1000][1000];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
priority_queue<Node, vector<Node>, cmp> pq;

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			pq.push({ map[i][j], i, j });
		}
	}

	// solve
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();

		if (isBombed[now.row][now.col] == 1) continue;
		isBombed[now.row][now.col] = 1;
		answer = map[now.row][now.col];

		for (int i = 0; i < 4; i++)
		{
			int ny = now.row + dir[i][0];
			int nx = now.col + dir[i][1];

			if (ny < 0 || ny >= N || nx < 0 || ny >= N) continue;
			isBombed[ny][nx] = 1;
		}
	}

	// output
	cout << answer << "초";

	return 0;
}
*/

/* mincoding - Level.35 #5. Ugly Number
#include <iostream>
#include <queue>
using namespace std;

int N;
long long order[1501];
int th;
long long previosNumber;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void uglyNumbers()
{
	th = 1;
	previosNumber = -1;
	pq.push(1);

	while (th <= 1500)
	{
		long long now = pq.top();
		pq.pop();
		if (previosNumber == now) continue;

		order[th] = now;
		previosNumber = now;
		th++;

		pq.push(now * 2);
		pq.push(now * 3);
		pq.push(now * 5);
	}
}

int main()
{
	uglyNumbers();
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		cout << order[input] << " ";
	}

	return 0;
}
*/