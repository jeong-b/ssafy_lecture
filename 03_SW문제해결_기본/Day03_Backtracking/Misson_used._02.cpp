#include <iostream>
using namespace std;

int limit, sum;
int path[10];
int used[7];

void run(int level)
{
	if (level >= limit)
	{
		for (int i = 0; i < limit; i++)
		{
			cout << path[i] << " ";
		}
		cout << sum << "\n";
		return;
	}
	for (int i = 1; i <= 6; i++)
	{
		if (used[i] == 1) { continue; }

		path[level] = i;
		used[i] = 1;
		sum += i;

		run(level + 1);

		used[i] = 0;
		path[level] = 0;
		sum -= i;
	}
}


int main()
{
	cin >> limit;
	run(0);

	return 0;
}