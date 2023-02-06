/* DAT - 문자열에서 문자의 개수를 세는 방법 */
#include <iostream>
using namespace std;

int main()
{
	char temp[12];
	cin >> temp;

	int DAT[256] = { 0, }; 
    // 기본적인 문자(Ascil code) : 128가지
    // char라는 data가 표현 가능 한 종류 : 256가지
	for (int i = 0; i < 12; i++)
	{
		char now = temp[i];
		DAT[now]++;
	}

    return 0;
}