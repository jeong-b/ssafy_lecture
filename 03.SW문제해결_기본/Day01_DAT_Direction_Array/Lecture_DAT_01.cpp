#include<iostream>
using namespace std;
/*
abcccbdeeab <- 길이 : 11
a의 개수 : 2 <- 11번
b의 개수 : 3 <- 11번
c의 개수 : 3 <- 11번
d의 개수 : 1 <- 11번
e의 개수 : 2 <- 11번

하고 싶은 것 : '문자' -> 해당 문자가 몇개?

DAT : Direct Address Table
 -> 배열의 index에 의미를 부여
int DAT[];
// index : 문자,
   value : 해당 문자가 몇 개?
*/

int main() {
    DAT
    char temp[100];
    cin >> temp;

    int DAT[256] = {0,};
    // 기본적인 문자(Ascii code) : 128가지, char라는 data가 표현 가능한 종류 : 256가지
    // index : 문자
    // value : 해당 문자가 몇 개 ?
    for (int i = 0; temp[i]; i++) // <- 11번
    {
       char now = temp[i];
       DAT[now]++; // now라는 문자가 1개 추가
    }

    return 0;    
}