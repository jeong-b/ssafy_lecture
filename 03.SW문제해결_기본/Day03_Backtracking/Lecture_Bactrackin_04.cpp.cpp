/* 주사위를 던져 조합이 중복되지 않는 경우 */
#include <iostream>
using namespace std;

char path[2];

void run(int level, int start)
{
	if (level == 2)
	{
		cout << path << "\n";
		return;
	}

	for (int i = start; i <= 6; i++)
	{
		path[level] = i + '0';
		run(level + 1, i);
		path[level] = 0;
	}
}

int main()
{
	run(0, 1);

	return 0;
}