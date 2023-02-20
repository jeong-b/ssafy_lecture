#include <iostream>
#include <vector>
using namespace std;

int N;
int used[51];
int cnt = 0;
vector<int> v;

void run(int sum)
{
	// #2. 기저조건
	if (sum == N)
	{
		cnt++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		// #4. 가지 치기
		if (used[i] == 2) continue;
		if (i < v.back()) continue;
		if (sum + i > N) break;

		// #3. 기록 및 처리
		used[i] += 1;
		v.push_back(i);

		// #1. 재귀 기본 구조
		run(sum + i);

		// #5. 복구
		used[i] -= 1;
		v.pop_back();
	}
}

int main()
{
	// input
	cin >> N;

	// solve
	v.push_back(0);
	run(0);

	// output
	cout << cnt;

	return 0;
}