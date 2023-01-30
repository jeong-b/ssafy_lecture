#include <iostream>
#include <cstring>
using namespace std;

int number, start, finish;
string headline[10];
string code;

void run(int level, int index)
{
	if (level >= headline[index].length()) return;
	if (level == 0) finish = 0;
	for (int i = finish; i < headline[index].length(); i++)
	{
		start = headline[index].find('[', finish);
		finish = headline[index].find(']', start);		

		if (start == -1 || finish == -1 || finish - start - 1 != 5) return;

		code = headline[index].substr(start, 7);
		cout << code << "\n";
		
		run(level + finish, index);
	}
}


int main()
{
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cin >> headline[i];
		run(0, i);
	}
	
	return 0;
}