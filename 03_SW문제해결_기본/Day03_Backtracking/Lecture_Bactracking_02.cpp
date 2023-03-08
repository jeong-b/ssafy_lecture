/* 문자열에서 원소를 재배열 하는 모든 경우 */
#include <iostream>
#include <cstring>
using namespace std;

char name[10];// = "BTSGOOD";
char path[3];

void run(int level, int len)
{
	if (level == 3)
	{
		cout << path << "\n";
		return;
	}

	for (int i = 0; i < len; i++)
	{
		path[level] = name[i];
		run(level + 1, len);
	}
}

int main()
{
	cin >> name;
	int len = strlen(name);
	run(0, len);

	return 0;
}
