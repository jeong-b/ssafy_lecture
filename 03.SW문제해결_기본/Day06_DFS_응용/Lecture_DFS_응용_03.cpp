// 노드에 연결된 경로 찾기
#include <iostream>
using namespace std;

int map[6][6] = {
	0, 1, 1, 0, 0, 0,
	0, 0, 0, 1, 1, 0,
	0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0
};
char name[6] = { 'A', 'B', 'T', 'R', 'V', 'G' };
char path[3];

void dfs(int now, int level)
{	
	if (level == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		if (map[now][i] == 0) continue;	
		path[level] = name[i];
		dfs(i, level + 1);
		path[level] = 0;
	}
}

int main()
{
	path[0] = name[0];
	dfs(0, 1);

	return 0;
}