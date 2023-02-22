#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node { int y, x; };

int arr[3][3] = { 
	15, 11, -7,
	55, -7, 11,
	-7, -55, -9
};
unordered_map<int, vector<Node>> um;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			um[arr[i][j]].push_back({ i, j });
		}
	}

	int N;
	cin >> N;

	if (um.count(N) != 0)
	{
		int len = um[N].size();
		for (int i = 0; i < len; i++)
		{
			Node result = um[N][i];
			cout << result.y << ',' << result.x << '\n';
		}
	}
	else cout << "없음";

	return 0;
}