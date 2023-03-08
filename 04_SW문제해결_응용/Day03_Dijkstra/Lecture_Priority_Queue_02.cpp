/* mincoding - Level.35 #6. 정중앙 대학교
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, less<int>> leftPQ;
	priority_queue<int, vector<int>, greater<int>> rightPQ;
	int N;
	int center = 500;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// reset
		int inputNum_1, inputNum_2;

		// input
		cin >> inputNum_1 >> inputNum_2;

		if (inputNum_1 > center) rightPQ.push(inputNum_1);
		else leftPQ.push(inputNum_1);

		if (inputNum_2 > center) rightPQ.push(inputNum_2);
		else leftPQ.push(inputNum_2);

		// solve
		if (leftPQ.size() > rightPQ.size())
		{
			rightPQ.push(center);
			center = leftPQ.top();
			leftPQ.pop();
		}
		if (leftPQ.size() < rightPQ.size())
		{
			leftPQ.push(center);
			center = rightPQ.top();
			rightPQ.pop();
		}

		// output
		cout << center << "\n";
	}

	return 0;
}
*/