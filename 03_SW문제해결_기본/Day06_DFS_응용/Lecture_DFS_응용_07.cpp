// 0번 노드에서 3번 노드까지 가는 최소비용 경로 구하기
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 50, 60, 300,
	0, 0, 7, 0,
	30, 0, 0, 10,
	0, 0, 0, 0
};
int used[4];
int minValue = 21e8;

void dfs(int now, int sum)
{
	if (now == 3)
	{
		if (sum < minValue) minValue = sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1) continue;

		used[i] = 1;
		dfs(i, sum + map[now][i]);
		used[i] = 0;
	}

}

int main()
{
	used[0] = 1;
	dfs(0, 0);
	cout << minValue;

	return 0;
}