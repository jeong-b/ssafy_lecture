// unordered_map 기본
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int arr[] = { 1, 200000000, 30000000, 4, 5, 1, 200000000 };

	// map 생성 - unordered_map<key type, value type>
	unordered_map<int, int> um;

	for (int i = 0; i < 7; i++)
	{
		if (um.find(arr[i]) != um.end()) um[arr[i]]++;
		else um.insert({ arr[i], 1 });
	}

	cout << um[200000000];

  // traversal / iteration 
  for (auto it = um.begin(); it != um.end(); it++) {
      cout << it->first << " " << it->second << '\n';
  }

	return 0;
}