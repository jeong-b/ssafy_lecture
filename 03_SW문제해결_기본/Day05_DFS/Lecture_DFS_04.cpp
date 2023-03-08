// 경로 저장
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[6];
vector<int> path;
int used[6];

void dfs(int now)
{
	// 2. 기져 조건
	if (now == 5)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
	{
		// now -> to 찾기
		int to = v[now][i];

		// 4. 가지치기
		if (used[to] == 1) continue;

		// 3. 기록 및 처리
		cout << now << "에서 " << to << "로 갑니다!\n";
		used[to] = 1;
		path.push_back(to);

		// 1. 재귀 기본  구조
		dfs(to);

		// 5. 복구
		path.pop_back();
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

	path.push_back(1);
	used[1] = 1;
	dfs(1);

	return 0;
}