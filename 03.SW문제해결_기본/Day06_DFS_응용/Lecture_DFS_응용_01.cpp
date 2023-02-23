// 도착위치로 가장 많이 연결된 노드 찾기

#include <iostream>
using namespace std;

int vect[5][5] = {
	0, 1, 0, 0, 0,
	0, 0, 1, 1, 0,
	0, 0, 0, 1, 1,
	0, 0, 0, 0, 0,
	0, 0, 0, 1, 0
};
int arr[5] = { 9, 8, 15, 22, 4 };

int main()
{
	int maxIndex = 0, maxValue = 0;
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += vect[j][i];
		}
		if (sum > maxValue)
		{
			maxValue = sum;
			maxIndex = i;
		}
	}
	cout << arr[maxIndex];

	return 0;
}