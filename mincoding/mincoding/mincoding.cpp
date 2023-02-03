#include <iostream>
#include <vector>
using namespace std;

int map[5][4];
int dirLine[3] = { 1, 2, 3 };
vector<int> deleteLine;
int flag;


int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (map[i][0] == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				int nx = dirLine[j];
				if (map[i][nx] == 0) 
				{
					flag = 0;
					break;
				}
				flag = 1;
			}
		}

		if (flag == 1)
		{
			map[i][0] = 0;
			for (int j = 0; j < 3; j++)
			{
				int nx = dirLine[j];
				map[i][nx] = 0;
			}
			deleteLine.push_back(i);
		}
		flag = 0;
	}

	for (int i = 0; i < deleteLine.size(); i++)
	{
		for (int j = deleteLine[i] - 1; j >= 0; j--)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = j + 1;
				map[ny][k] = map[j][k];
			}
		}
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	
	return 0;
}