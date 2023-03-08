// 인접 리스트
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	vector<int> v[6]; // vector<저장할 Data 자료형> v;

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to); // vector.push_back(value) : vector 맨 뒤에 공간을 추가해서 value라는 값을 저장
	}

	int node = 1; // from의로 사용할 위치

	for (int i = 0; i < v[node].size(); i++) // vector.size() : vector가 갖고 있는 Data 개수
	{
		int to = v[node][i];
		cout << to << " "; // 갈 수 있는 to를 출력
	}

	return 0;
}