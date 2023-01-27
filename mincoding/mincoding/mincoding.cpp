#include <iostream>
using namespace std;

int main()
{
	int board[7][7] = {
		0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 1, 0, 0,
		0, 1, 2, 0, 2, 1, 0,
		0, 0, 1, 2, 1, 0, 0,
		0, 0, 2, 1, 0, 1, 0,
		0, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0
	};
	int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	int inputY, inputX, cnt = 0;
	cin >> inputY >> inputX;
	board[inputY][inputX] = 1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 2)
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dir[k][0];
					int nx = j + dir[k][1];
					if (board[ny][nx] != 1) { break; }
					cnt = 1;
				}
			}
		}
	}
	cout << cnt;


	return 0;
}