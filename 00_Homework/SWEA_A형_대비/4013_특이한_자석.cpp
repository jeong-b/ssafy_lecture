#include <iostream>
#include <cstring>
using namespace std;

int T, turnCnt;
int magnet[4][8];
int newMagnet[4][8];

void turn (int num, int dir, int dMove)
{
	// #2. 기저조건
	if (num < 1 || num > 4) return;
	
	int index = num - 1;
	int dLeft = -1, dRight = -1;
	if (index > 0) dLeft = magnet[index - 1][2];
	if (index < 3) dRight = magnet[index + 1][6];

	if (dir == 1)
	{
		if (magnet[index][6] != dLeft && dLeft != -1 && dMove != 1) turn(num - 1, -1, -1);
		if (magnet[index][2] != dRight && dRight != -1 && dMove != -1) turn(num + 1, -1 ,1);
		
		for (int i = 0; i < 7; i++) newMagnet[index][i + 1] = magnet[index][i];
		newMagnet[index][0] = magnet[index][7];
	}

	if (dir == -1)
	{
		if (magnet[index][6] != dLeft && dLeft != -1 && dMove != 1) turn(num - 1, 1, -1);
		if (magnet[index][2] != dRight && dRight != -1 && dMove != -1) turn(num + 1, 1, 1);
		
		for (int i = 7; i > 0; i--) newMagnet[index][i - 1] = magnet[index][i];
		newMagnet[index][7] = magnet[index][0];
	}
}

int main(int argc, char** argv)
{
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// reset
		int sum = 0;

		// input
		cin >> turnCnt;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{				
				cin >> magnet[i][j];
			}
		}

		for (int i = 0; i < turnCnt; i++)
		{
			int magnetNum, turnDir;
			cin >> magnetNum >> turnDir;

			memcpy(newMagnet, magnet, sizeof(magnet));
			turn(magnetNum, turnDir, 0);
			memcpy(magnet, newMagnet, sizeof(magnet));
		}

		// solve
		sum = magnet[0][0] * 1;
		sum += magnet[1][0] * 2;
		sum += magnet[2][0] * 4;
		sum += magnet[3][0] * 8;

		// output
		cout << '#' << test_case << ' ' << sum << '\n';		
	}

	return 0;
}