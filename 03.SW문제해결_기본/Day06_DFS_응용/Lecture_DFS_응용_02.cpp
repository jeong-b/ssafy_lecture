// 노드에 연결된 값 찾기
#include <iostream>
using namespace std;

int vect[4][4] = {
	0, 1, 0, 1,
	0, 0, 0, 1,
	1, 0, 0, 1,
	0, 0, 0, 0,
};
int arr[4] = { 15, 99, 88, -77 };
int nodeIndex;

int main()
{
	cin >> nodeIndex;
	for (int i = 0; i < 4; i++)
	{
		if (vect[nodeIndex][i] == 1)
		{
			cout << arr[i] << " ";
		}
	}

	return 0;
}