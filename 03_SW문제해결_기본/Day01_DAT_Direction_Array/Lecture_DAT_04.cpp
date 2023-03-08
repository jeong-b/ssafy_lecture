/* DAT - 배열 속 숫자 세기*/
#include <iostream>
using namespace std;

int main()
{
	int arr[6] = { 1, 5, 2, 2, 2, 9 };
	int dat[10] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		dat[arr[i]]++;
	}
	for (int i = 1; i <= 3; i++)
	{
		cout << i << ":" << dat[i] << "개\n";
	}

	return 0;
}