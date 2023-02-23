// 한 노드에서 특정 노드가 연결 되어있는지 확인
#include <iostream>
using namespace std;

int map[4][4] = {
	0, 1, 1, 1,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 0, 0, 0
};
int used[4];
int flag;

void dfs(int now, int finish)
{
	if (now == finish)
	{
		flag = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[now][i] == 0) continue;
		if (used[i] == 1) continue;
		if (flag == 1) continue;

		used[i] = 1;
		
		dfs(i, finish);
	}
}

int main()
{
	dfs(0, 3);
	if (flag == 1) cout << "O";
	else cout << "X";
	
	return 0;
}