// parametic search
#include <iostream>
using namespace std;

int N;
int arr[4];
int maxValue;

bool condition(int val)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > val) sum += val;
		else sum += arr[i];
	}

	if (sum > maxValue) return false;
	else return true;
}

void ps(int low, int high)
{
	int left = low;
	int right = high;
	int answer = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (condition(mid) == true)
		{
			answer = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << answer;
}

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> maxValue;

	// solve
	ps(0, maxValue);

	return 0;
}