// 인접 리스트
#include <iostream>
using namespace std;

int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	int adj[6][6] = { 0 };

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	int node = 1; // from의로 사용할 위치

	for (int i = 1; i <= 5; i++)
	{
		if (adj[node][i] == 0) continue;
		cout << i << " "; // 갈 수 있는 to를 출력
	}

	return 0;
}