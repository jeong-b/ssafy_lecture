// 인접리스트를 활용한 연결된 노드 찾기
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr(5); 
int node;

void run(int now)
{
	cout << now;

	for (int i = 0; i < arr[now].size(); i++)
	{
		run(arr[now][i]);
	}

}

int main()
{
	//arr.push_back({});
	//arr.push_back({});
	//arr.push_back({});
	//arr.push_back({});
	//arr.push_back({});
	
	arr[0] = { 3 };
	arr[1] = { 2, 0 };
	arr[3] = { 4, 2 };
	arr[4] = { 2 };

	//for (int i = 0; i < arr.size(); i++)
	//{
	//	for (int j = 0; j < arr[i].size(); j++)
	//	{
	//		cout << arr[i][j];
	//	}
	//	cout << "\n";
	//}
	cin >> node;

	for (int i = 0; i < arr[node].size(); i++)
	{
		cout << arr[node][i];
	}

	return 0;
}