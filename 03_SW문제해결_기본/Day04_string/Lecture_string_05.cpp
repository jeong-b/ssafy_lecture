/* string 메서트 - 문자열 부분 복사 */
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    char a[100] = "string";
    char b[100];
    int st, en; // 2개의 정수 입력 -> 2 6 
    cin >> st >> en; 
    
    // 기본 방법
    int idx = 0; 
    for (int i = st; i < en; i++) {
        b[idx] = a[i];
        idx++; 
    }
    b[idx] = '\0'; 
    cout << b; 
    
    // cstring library - strncpy(복사를 해서 저장할 위치, 복사를 할 위치, 복사를 할 구간 크기)
    a[100] = "string";
    b[100];
    cin >> st >> en; 

    strncpy(b, a + st, en - st);
    b[en-st] = '\0';
    cout << b;
       
    // string class - substr()
    // substr(시작위치(index), 구간 크기(index))
    // 만약 구간 크기가 문자열의 길이를 넘어간다면
    // -> 알아서 마지막까지로 짤라준다.
    string c = "string";
    string d;
    d = c.substr(st, en - st);
    cout << d;

  return 0;
}