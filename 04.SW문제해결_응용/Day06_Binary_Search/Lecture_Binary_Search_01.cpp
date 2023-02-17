// Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = { 3, 99, 21, 33, 4, 1, 5, 55, 7, 10 };

int bs(int target)
{
	// #1. 탐색 범위 지정
	int left = 0;
	int right = 9;
	int flag = 0;

	// #2. 탐색
	while (left <= right)
	{
		// #3. 중앙값 선정
		int mid = (left + right) / 2;

		// #4. 탐색
		if (arr[mid] == target) return mid;		
		else if (arr[mid] > target) right = mid - 1;		
		else if (arr[mid] < target) left = mid + 1;		
	}

	return -1;
}

int main()
{
	// input
	int target;
	cin >> target;

	// solve
	sort(arr, arr + 10);
	int result = bs(target);

	// output
	if (result != -1) cout << result;
	else cout << "미발견";

	return 0;
}