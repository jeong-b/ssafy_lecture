/* string 메서드 - 문자열 결합*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{    
    char a[100] = "str";
    char b[100] = "ing"; 

    // 기본 방법    
    int lena = strlen(a);
    int lenb = strlen(b); 
    
    for (int i = 0; i < lenb; i++) {
       a[i+lena] = b[i]; 
    }
    a[lena + lenb] = '\0'; 
    
    cout << a << '\n';    
    

    // cstring library - strcat 
    // strcat(a,b) => b가 a에 결합
    strcat(a, b);
    cout << a <<'\n'; 
    
    // string class - += 결합
    string c = "str";
    string d = "str"; 
    c += d; 
    cout << c;

  return 0;
}