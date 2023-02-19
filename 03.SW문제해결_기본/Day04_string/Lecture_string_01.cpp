/* string 메서드 - 문자열의 길이 */
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100] = "string";
    string s = "string"; 

    // character 배열 - 기본 방법
    int len = 0;
    int idx = 0;
    while (str[idx] != '\0') {
        len++;
        idx++; 
    }
    cout << len << '\n';

    // character 배열 - cstring library
    cout << strlen(str) << '\n'; 

    // string - cstring library
    cout << s.length(); 

    return 0;
}