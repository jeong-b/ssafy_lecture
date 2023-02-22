#include <iostream>
#include <unordered_map>
using namespace std;

struct Node { string name, age, IQ; };

unordered_map<string, Node> um;

int main()
{
	um.insert({ "56", { "so", "15", "56"}});
	um.insert({ "60", { "go", "66", "60"}});
	um.insert({ "150", { "gi", "15", "150"}});

	um.insert({ "so", { "so", "15", "56"}});
	um.insert({ "go", { "go", "66", "60"}});
	um.insert({ "gi", { "gi", "15", "150"}});

	string input;
	cin >> input;

	if (um.count(input) > 0)
	{
		if (um[input].name != input) cout << "name: " << um[input].name << "\n";
		if (um[input].IQ != input) cout << "name: " << um[input].IQ << "\n";
		cout << "age: " << um[input].age;
	}	

	return 0;
}