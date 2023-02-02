#include <iostream>
#include <cstring>
using namespace std;

char a[3][3], b[3][3];
int cnt, flag;

void turn(char arr[3][3])
{
	char turned[3][3];
	turned[0][0] = arr[0][2];
	turned[0][1] = arr[1][2];
	turned[0][2] = arr[2][2];
	turned[1][0] = arr[0][1];
	turned[1][1] = arr[1][1];
	turned[1][2] = arr[2][1];
	turned[2][0] = arr[0][0];
	turned[2][1] = arr[1][0];
	turned[2][2] = arr[2][0];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = turned[i][j];
		}
	}
}

void run(char c[3][3], char d[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (strcmp(c[i], d[i]) == 0) flag += 1;
		else flag = 0;
	}
	if (flag == 3)
	{
		cnt++;
		return;
	}
	turn(c);
	run(c, d);

}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> b[i][j];
		}
	}

	run(a, b);
	cout << cnt;

	return 0;
}