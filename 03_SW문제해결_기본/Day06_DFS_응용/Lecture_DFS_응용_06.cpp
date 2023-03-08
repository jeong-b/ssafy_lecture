// 한 노드에서 특정 노드로 가는 경로의 개수 확인
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];
int cnt = 0;

void dfs(int now, int finish)
{
	if (now == finish)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;

		dfs(i, finish);

		used[i] = 0;
	}
}

int main()
{
	used[0] = 1;
	dfs(0, 3);
	cout << cnt;

	return 0;
}