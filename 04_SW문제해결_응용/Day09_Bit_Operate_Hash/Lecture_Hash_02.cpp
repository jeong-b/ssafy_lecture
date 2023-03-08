// 문자열 배열의 같은 단어 나온 횟수 확인
#include <iostream>
#include <unordered_map>
using namespace std;

string arr[] = { "HI", "HI", "HELLO", "HI", "HELLO" };

int main()
{
	// 기본 방법
	string str;
	int cnt = 0;

	cin >> str;

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == str) cnt++;
	}

	cout << cnt;

	// unordered_map 사용
	string str;

	cin >> str;

	unordered_map<string, int> um;
	for (int i = 0; i < 5; i++)
	{
		um[arr[i]] += 1;
	}

	if (um.count(str) == 0) cout << -1;
	else cout << um[str];

	return 0;
}