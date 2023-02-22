#include <iostream>
#include <algorithm>
using namespace std;

int memo[100001];

int getMin(int price)
{
	if (price < 0) return 21e8;
	if (price == 0) return 0;
	if (memo[price] != 0) return memo[price];

	int a = getMin(price - 10) + 1;
	int b = getMin(price - 50) + 1;
	int c = getMin(price - 70) + 1;

	int result = min(min(a, b), c);
	memo[price] = result;
	return result;
}

int main()
{
	cout << getMin(1000);

	return 0;
}