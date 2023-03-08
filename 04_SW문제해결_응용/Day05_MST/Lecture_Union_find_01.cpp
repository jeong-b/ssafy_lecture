/* Union-Find
*/
#include <iostream>
using namespace std;

struct Node
{
	int y, x;
};

int mapSizeY, mapSizeX;
int groundCnt;
int map[100][100];
int groundSize[100][100];
Node parent[100][100];

void initParent()
{
    for (int i = 0; i < mapSizeY; i++)
    {
        for (int j = 0; j < mapSizeX; j++)
        {
            parent[i][j] = { -1, -1 };
        }
    }
}

int main()
{
	// reset


	// input
	cin >> mapSizeY >> mapSizeX;
    initParent();
	cin >> groundCnt;
	for (int i = 0; i < groundCnt; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
		groundSize[y][x] = 1;
	}	

	// solve


	// output

	return 0;
}


/**/

Node Find(Node now)
{
    Node p = parent[now.row][now.col];
    if (now.row == p.row && now.col == p.col)
    {
        return now;
    }
    Node ret = Find(parent[now.row][now.col]);
    parent[now.row][now.col] = ret;
    return ret;
}

int total = 0;

void Union(Node a, Node b)
{
    Node ra = Find(a);
    Node rb = Find(b);
    if (ra.row == rb.row && ra.col == rb.col) return;
    parent[rb.row][rb.col] = ra;
    sizeOf[ra.row][ra.col] += sizeOf[rb.row][rb.col];
    sizeOf[rb.row][rb.col] = 0;
}

int main()
{
    for (int i = 0; i < Q; i++)
    {
        int row, col;
        cin >> row >> col;
        parent[row][col] = { row,col }; // init 
        sizeOf[row][col] = 1;
        for (int t = 0; t < 4; t++)
        {
            int nr = row + dr[t];
            int nc = col + dc[t];
            if (isOut(nr, nc))continue;
            // if (Find({ nr,nc }) == {-1, -1})continue; 
            if (parent[nr][nc].row == -1 && parent[nr][nc].col == -1)continue;
            Union({ row,col }, { nr,nc });
        }
    }

    // root 가 몇개인가 
    int total = 0;
    int maxSize = -1;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            Node r = Find({ row,col });
            if (row == r.row && col == r.col)
            {
                total++;
                maxSize = max(sizeOf[row][col], maxSize);
            }
        }
    }


    return 0;
}