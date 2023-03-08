#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Info { int y, x, cnt, dirNum; };

bool cmp(Info left, Info right)
{
	if (left.cnt > right.cnt) return true;
	if (left.cnt < right.cnt) return false;

	return false;
}

int T;
int cellCnt, leadTime, crowdCnt;
int len, sum;
vector<int> keys;
vector<Info> originMap;
unordered_map<int, Info> copyMap;

void run(int level)
{
	// #2. 기저 조건
	if (level == leadTime) return;
	
	// #3. 기록 및 처리
	keys.clear();
	copyMap.clear();
	sort(originMap.begin(), originMap.end(), cmp);
	len = originMap.size();
	for (int i = 0; i < len; i++)
	{
		int ny = originMap[i].y, nx = originMap[i].x, virusCnt = originMap[i].cnt, dir = originMap[i].dirNum;
		
		if (dir == 1) ny -= 1;
		else if (dir == 2) ny += 1;
		else if (dir == 3) nx -= 1;
		else if (dir == 4) nx += 1;

		if (ny == 0) dir = 2;
		else if (nx == 0) dir = 4;
		else if (ny == cellCnt - 1) dir = 1;
		else if (nx == cellCnt - 1) dir = 3;

		int position = (ny * cellCnt) + nx;

		if (copyMap.count(position) == 0)
		{
			copyMap.insert({ position, {ny, nx, virusCnt, dir} });
			keys.push_back(position);
		}
		else copyMap[position].cnt += virusCnt;
	}

	originMap.clear();
	len = keys.size();
	for (int i = 0; i < len; i++)
	{
		int position = keys[i];
		int ny = position / cellCnt, nx = position % cellCnt;

		if (copyMap.count(position) == 0) continue;

		if (ny == 0 || ny == cellCnt - 1 || nx == 0 || nx == cellCnt - 1) copyMap[position].cnt /= 2;

		originMap.push_back({ ny, nx, copyMap[position].cnt, copyMap[position].dirNum });
	}

	// #1. 재귀 기본구조
	run(level + 1);
}

int main(int argc, char** argv)
{
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// reset
		originMap.clear();
		sum = 0;

		// input
		cin >> cellCnt >> leadTime >> crowdCnt;
		for (int i = 0; i < crowdCnt; i++)
		{
			int y, x, cnt, dirNum;
			cin >> y >> x >> cnt >> dirNum;
			originMap.push_back({ y, x, cnt, dirNum });
		}

		// solve
		run(0);
		len = originMap.size();
		for (int i = 0; i < len; i++) sum += originMap[i].cnt;

		// output
		cout << '#' << test_case << ' ' << sum << '\n';
	}

	return 0;
}