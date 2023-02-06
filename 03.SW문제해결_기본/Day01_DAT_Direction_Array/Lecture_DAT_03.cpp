/* DAT - 문자열 속 가장 많이 등장한 문자 찾기 */
#include <iostream>
using namespace std;

int main() {
	
	char arr[100] = { 0 };
	int dat[256] = { 0 };
	int max = 0;
	char maxch;

	cin >> arr;

	for (int i = 0; i < 10; i++)
	{
		dat[arr[i]]++;
		if (dat[arr[i]] > max)
		{
			max = dat[arr[i]];
			maxch = arr[i];
		}
	}

	cout << maxch;

	return 0;
}