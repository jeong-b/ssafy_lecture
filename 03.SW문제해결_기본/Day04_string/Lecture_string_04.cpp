/* strintg 메서드 - 문자열 전체 복사 */
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[100] = "string";
    char b[100]; 

    int lena = strlen(a); 
    for (int i = 0; i < lena; i++) {
       b[i] = a[i]; 
    }
    b[lena] = '\0'; 
    cout << b; 
    

    // cstring library - strcpy 
    // strcpy(복사하고자 하는 문자열의 위치, 복사하려고 하는 문자열)
    strcpy(b, a); 
    cout << b << '\n';

    // string class
    string c = "string";
    string d;
    d = c; 
    cout << d << '\n';
    
    return 0;
}