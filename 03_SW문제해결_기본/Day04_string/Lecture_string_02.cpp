/* string 기본 메서드 -  문자열 비교*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[100] = "abc";
    char b[100] = "abc"; 
    
    // 기본 방법 - 배열의 길이 비교 후 각 index별로 비교
    if (strlen(a) != strlen(b)) cout << 0; 
    else
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] != b[i])
            {
                cout << 0;
                return 0;
            }
        }
        cout << 1; 
    }

    cout << "\n";

    // cstring library - strcmp 
    // a == b : 0
    // a != b : -1->a가 b보다 사전순으로 앞에온다, 
    // 또는 1-> a가 b보다 사전순으로 늦게온다 
    if (strcmp(a, b) == 0) cout << 1;
    else cout << 0;

    return 0;
}