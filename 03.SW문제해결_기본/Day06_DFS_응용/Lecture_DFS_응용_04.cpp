// 모든 노드 탐색하고 경로 출력하기
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];

void dfs(int now)
{
	cout << now;
	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] >= 1) continue;
		used[i] = 1;
		dfs(i);
		// used[i] = 0; 을 사용하지 않으면 연결된 Node를 한번씩만 탐색한다.
		// used[i] = 1; 을 사용하면 모든 경로를 탐색한다.
		used[i] = 0;
	}
}

int main()
{
	used[0] = 1;
	dfs(0);
	return 0;
}