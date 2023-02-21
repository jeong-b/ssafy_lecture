// Graph를 활용하는 재귀함수 - 인접 행렬 활용
#include <iostream>
using namespace std;

int nodeCnt, edgeCnt;
int adj[6][6];

void dfs(int now)
{
	// 2. 기저 조건(option) - 생략가능한 이유 : 가지치기를 통해 재귀를 시키지 않음

	for (int to = 1; to <= nodeCnt; to++)
	{
		// 4. 가지치기
		if (adj[now][to] == 0) continue; // now -> to 로 갈 수 없으면 무시
		
		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		
		// 1. 재귀 기존 구조
		dfs(to);
	}
}

int main()
{
	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}

	dfs(1);

	return 0;
}