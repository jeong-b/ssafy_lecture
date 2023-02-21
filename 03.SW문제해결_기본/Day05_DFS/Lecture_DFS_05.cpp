// 모든 경우의 수 구하기
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[7];
vector<int> path;
int used[8];
int cnt;

void dfs(int now)
{
	// 2. 기져 조건
	if (now == 7)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		cnt++;
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
		used[to] = 0;
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

	cout << "경로의 수 : " << cnt << "\n";

	return 0;
}