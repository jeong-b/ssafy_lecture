#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Position { int y, x; };

int T, N;
int score;
int dirChange;
int map[102][102];
int dist_1[102][102];
int dist_2[102][102];
int dist_3[102][102];
int dist_4[102][102];
vector<Position> startPoint;
vector<Position> wormHole[5];

void run(int y, int x, int dirNum)
{
	score = 0;
	dirChange = 0;

	// queue
	queue<Position> q;
	q.push({ y, x });

	// bfs
	while (!q.empty())
	{
		Position now = q.front();
		q.pop();

		int ny = now.y, nx = now.x;

		if (map[ny][nx] >= 6 && map[ny][nx] <= 10)
		{
			int holeNum = map[ny][nx] - 6;
			if (ny == wormHole[holeNum][0].y && nx == wormHole[holeNum][0].x)
			{
				ny = wormHole[holeNum][1].y;
				nx = wormHole[holeNum][1].x;
			}
			else if (ny == wormHole[holeNum][1].y && nx == wormHole[holeNum][1].x)
			{
				ny = wormHole[holeNum][0].y;
				nx = wormHole[holeNum][0].x;
			}
		}

		if (dirNum == 1) ny -= 1;
		if (dirNum == 2) ny += 1;
		if (dirNum == 3) nx -= 1;
		if (dirNum == 4) nx += 1;

		if ((ny == y && nx == x) || map[ny][nx] == -1) break;
		
		if (map[ny][nx] == 5)
		{
			score = (score * 2) + 1;
			break;
		}
		if ((map[ny][nx] == 1 || map[ny][nx] == 4) && dirNum == 1)
		{
			score = (score * 2) + 1;
			break;
		}
		if ((map[ny][nx] == 2 || map[ny][nx] == 3) && dirNum == 2)
		{
			score = (score * 2) + 1;
			break;
		}
		if ((map[ny][nx] == 3 || map[ny][nx] == 4) && dirNum == 3)
		{
			score = (score * 2) + 1;
			break;
		}
		if ((map[ny][nx] == 1 || map[ny][nx] == 2) && dirNum == 4)
		{
			score = (score * 2) + 1;
			break;
		}

		if (map[ny][nx] == 2 && dirNum == 1)
		{
			dirNum = 4;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 3 && dirNum == 1)
		{
			dirNum = 3;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 1 && dirNum == 2)
		{
			dirNum = 4;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 4 && dirNum == 2)
		{
			dirNum = 3;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 1 && dirNum == 3)
		{
			dirNum = 1;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 2 && dirNum == 3)
		{
			dirNum = 2;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 3 && dirNum == 4)
		{
			dirNum = 2;
			dirChange = 1;
			score++;
		}
		else if (map[ny][nx] == 4 && dirNum == 4)
		{
			dirNum = 1;
			dirChange = 1;
			score++;
		}

		if (dirChange ==0 && dirNum == 1 && dist_1[ny][nx] != 0) continue;
		if (dirChange ==0 && dirNum == 2 && dist_2[ny][nx] != 0) continue;
		if (dirChange ==0 && dirNum == 3 && dist_3[ny][nx] != 0) continue;
		if (dirChange ==0 && dirNum == 4 && dist_4[ny][nx] != 0) continue;

		if (dirChange ==0 && dirNum == 1) dist_1[ny][nx] = 1;
		if (dirChange ==0 && dirNum == 2) dist_2[ny][nx] = 1;
		if (dirChange ==0 && dirNum == 3) dist_3[ny][nx] = 1;
		if (dirChange ==0 && dirNum == 4) dist_4[ny][nx] = 1;

		q.push({ ny, nx });
	}
}


int main(int argc, char** argv)
{
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// reset
		for (int i = 0; i < 102; i++)
		{
			for (int j = 0; j < 102; j++)
			{
				map[i][j] = 5;
				dist_1[i][j] = 0;
				dist_2[i][j] = 0;
				dist_3[i][j] = 0;
				dist_4[i][j] = 0;
			}
		}
		for (int i = 0; i < 5; i++) wormHole[i].clear();
		startPoint.clear();
		int result = 0;

		// input
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int input;
				cin >> input;
				map[i][j] = input;
				if (input == 0) startPoint.push_back({ i, j });
				if (input >= 6 && input <= 10) wormHole[input - 6].push_back({ i, j });
			}
		}

		// solve
		int len = startPoint.size();
		for (int i = 0; i < len; i++)
		{
			int startY = startPoint[i].y, startX = startPoint[i].x;

			run(startY, startX, 1);
			if (score > result) result = score;

			run(startY, startX, 2);
			if (score > result) result = score;

			run(startY, startX, 3);
			if (score > result) result = score;

			run(startY, startX, 4);
			if (score > result) result = score;
		}

		// output
		cout << '#' << test_case << ' ' << result << '\n';
	}

	return 0;
}