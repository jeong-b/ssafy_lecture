/* 배열의 원소의 곱에서의 최대 최소 구하기 */
#include <iostream>
using namespace std;

int vect[4][4] = {
	3, 1, 4, 2,
	1, 1, -1, 1,
	2, 3, 1, 4,
	5, 1, 0, 3,
};
int maxValue = -21e8;
int minValue = 21e8;

void run(int level, int gop)
{
	if (level == 4) 
	{
		if (maxValue < gop) maxValue = gop;
		if (minValue > gop) minValue = gop;
		//cout << gop << "\n";
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		run(level + 1, gop * vect[level][i]);
	}
}

int main()
{
	run(0, 1);
	cout << maxValue << "\n";
	cout << minValue;

	return 0;
}