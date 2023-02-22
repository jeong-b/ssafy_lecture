#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> um1;
unordered_map<string, string> um2;

int main()
{
	um1.insert({ "23", "Jordan" });
	um1.insert({ "10", "Lee" });
	um1.insert({ "61", "Park" });
	um1.insert({ "7", "Son" });

	um2.insert({ "Jordan", "23" });
	um2.insert({ "Lee", "10" });
	um2.insert({ "Park", "61"});
	um2.insert({ "Son", "7"});

	string input;
	cin >> input;

	if (um1.count(input) == 0 && um2.count(input) == 0) cout << -1;
	else if (um1.count(input) != 0 && um2.count(input) == 0) cout << um1[input];
	else if (um1.count(input) == 0 && um2.count(input) != 0) cout << um2[input];

	return 0;
}