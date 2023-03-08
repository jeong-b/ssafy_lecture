#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int arr1[10] = { 5,3,1,6,8,9,2,4,10,7 };	
	// 작은 값부터 순서대로 출력하기
	// #1. sort 사용하지 않고 정렬 -  내 방법 (기존 arr이 수정 됨)
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr1[i] > arr1[j])
			{
				int temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << "\n";

	// #1-2. sort 사용하지 않고 정렬 - 교수님 방법(기본 arr에 수정 안함)
	int prev = 0;
	for (int i = 0; i < 10; i++)
	{
		int minValue = 100;
		for (int x = 0; x < 10; x++)
		{
			if (prev < arr1[x] && arr1[x] < minValue)
			{
				minValue = arr1[x];
			}
		}
		prev = minValue;
		cout << minValue << " ";
	}
	cout << "\n";

	// #2. sort 사용하여 정렬
	sort(arr1, arr1 + 10); // [begin, end)
	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << "\n";

	// #3. vector의 정렬
	vector<int> arr2 = { 5,3,1,6,8,9,2,4,10,7 };

	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << "\n";

	for (int value : arr2) // arr2에 있는 원소 - 값복사 방법
	{
		cout << value << " ";
	}
	cout << "\n";

	for (const int& value : arr2) // arr2에 있는 원소 - 값참조 방법(const는 값이 바뀌는것을 막아줌)
	{
		cout << value << " ";
	}
	cout << "\n";

	return 0;
}