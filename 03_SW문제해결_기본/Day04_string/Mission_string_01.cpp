/* 문자열에서 특정 substring이 등장하는 위치 */
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{    
    char a[100] = "string";
    char b[100];
    cin >> b;     
    
    // 기본 방법
    for (int i = 0; strlen(a) - strlen(b); i++) {
        // 동일한 문자의 개수 
        int cnt = 0; 
        // 가능한 b 길이의 모든 위치 확인
        for (int j = 0; j < strlen(b); j++) {
            // 이 구간 내에 모든 문자 구성이 동일한가? 
            if (a[i + j] == b[j])
                cnt++; 
        }
        // 모든 구간이 동일하다면 cnt == strlen(b)
        if (cnt == strlen(b)) {
            cout << i; 
            return 0; 
        }
    }

    // cstring library - strstr(A, B) -> pointer를 return
    // -> 찾으려고 하는 문자열이 A에 존재한다면, 처음 찾은 위치를 기준으로 
    // 남은 문자열 전체를 반환
    cout << strstr(a, b);

    // string class - find()
    // str.find(내가 찾으려고 하는 substring) -> substring을 찾은 첫 index를 return
    string a = "stssst";
    string b = "g";
    // 찾을 수 있다면 어떠한 값 
    if (a.find(b) == -1) cout << 0;
    // 찾을 수 없다면
    else cout << 1; 

    return 0;
}