#include <iostream>
#include <queue>
using namespace std;

struct Node { int y, x; };

int T;
int height, width, holeY, holeX, leadTime;
int map[50][50];
int answer;

void bfs(int y, int x)
{
	// queue
	queue<Node> q;
	q.push({ y, x });

	// dist	
	int dist[50][50] = { 0 };	
	dist[y][x] = 1;
	answer++;

	// direction Array
	int dir[4][2] = {
		{-1, 0}, {1, 0}, {0, -1}, {0, 1}
	};

	// bfs
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		if (map[now.y][now.x] == 1)
		{
			for (int i = 0; i <= 3; i++)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;
				if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;
				if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;
				if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
		if (map[now.y][now.x] == 2)
		{
			for (int i = 0; i <= 1; i++)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;
				if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
		if (map[now.y][now.x] == 3)
		{
			for (int i = 2; i <= 3; i++)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;
				if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;
				if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
		if (map[now.y][now.x] == 4)
		{
			for (int i = 0; i <= 3; i += 3)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;
				if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
		if (map[now.y][now.x] == 5)
		{
			for (int i = 1; i <= 3; i += 2)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;				
				if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;
				if (i == 3 && (map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 5)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
		if (map[now.y][now.x] == 6)
		{
			for (int i = 1; i <= 2; i++)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;
				if (i == 1 && (map[ny][nx] == 3 || map[ny][nx] == 5 || map[ny][nx] == 6)) continue;
				if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
		if (map[now.y][now.x] == 7)
		{
			for (int i = 0; i <= 2; i += 2)
			{
				int ny = now.y + dir[i][0];
				int nx = now.x + dir[i][1];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (map[ny][nx] == 0) continue;
				if (i == 0 && (map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 7)) continue;
				if (i == 2 && (map[ny][nx] == 2 || map[ny][nx] == 6 || map[ny][nx] == 7)) continue;
				if (dist[ny][nx] != 0) continue;

				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] <= leadTime) answer++;
				q.push({ ny, nx });
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// reset
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				map[i][j] = 0;
			}
		}
		answer = 0;

		// input
		cin >> height >> width >> holeY >> holeX >> leadTime;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> map[i][j];
			}
		}

		// solve
		bfs(holeY, holeX);

		// output
		cout << '#' << test_case << ' ' << answer << '\n';
	}

	return 0;
}