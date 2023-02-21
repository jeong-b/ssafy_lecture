// Edge가 순환구조일때 무한재귀가 도는 것을 해결
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[6];
int used[6];

void dfs(int now)
{
	// 2. 기져 조건

	for (int i = 0; i < v[now].size(); i++)
	{
		// now -> to 찾기
		int to = v[now][i];
		
		// 4. 가지치기
		if (used[to] == 1) continue;
		
		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		used[to] = 1;
		
		// 1. 재귀 기본  구조
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
		v[from].push_back(to);
	}

	used[1] = 1;
	dfs(1);

	return 0;
}