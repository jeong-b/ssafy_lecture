#include <iostream>
using namespace std;

char map[4][4];
char monster[26][2];
int dir[5][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int dat[26];
int monsterIndex;

void input()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] >= 'A' && map[i][j] <= 'Z')
			{
				dat[map[i][j] - 'A']++;
				monster[map[i][j] - 'A'][0] = i;
				monster[map[i][j] - 'A'][1] = j;
			}
		}
	}
}

void changePosition(int time, int number)
{
	if (time == 5) return;
	
}

int main()
{
	input();
	changePosition(0, 0);

	return 0;
}