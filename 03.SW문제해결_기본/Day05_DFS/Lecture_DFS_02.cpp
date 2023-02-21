// Graph를 활용하는 재귀함수 - 인접 리스트 활용
#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[6];

void dfs(int now)
{
	for (int i = 0; i < v[now].size(); i++)
	{
		int to = v[now][i];
		cout << now << "에서 " << to << "로 갑니다!\n";
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

	dfs(1);

	return 0;
}