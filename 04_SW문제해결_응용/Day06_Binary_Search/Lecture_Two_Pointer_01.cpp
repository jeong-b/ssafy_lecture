// Two Pointer
#include <iostream>
using namespace std;

int main()
{
	int arr[10] = { 1, 2, 3, 1, 2, 3, 5, 6, 7, 8 };
	int target = 6;
	int left = 0;
	int right = 0;
	int sum = 0;
	int cnt = 0;

	while (left <= 10 && right <= 10)
	{
		if (sum == target)
		{
			cnt++;
			sum -= arr[left];
			left++;
		}
		else if (sum < target)
		{
			sum += arr[right];
			right += 1;
		}
		else if (sum > target)
		{
			sum -= arr[left];
			left += 1;
		}
	}

	cout << cnt;

	return 0;
}