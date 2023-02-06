/* 전역변수 vs. 지역변수*/
#include <iostream>
using namespace std;

int a = 3;

void func1() {
  a = 10;
  int b = 10;
  cout << a << " " << b << "\n";
}

void func2() {
  a = 7;
  int b = 7;
  cout << a << " " << b << "\n";
  func1();
  cout << a << " " << b << "\n"; 
}

int main() {
  int b = 5;
  cout << a << " " << b << "\n";
  func2();
  cout << a << " " << b << "\n";
  return 0;
}

/* 출력 값
a   b
3   5
7   7
10  10
10  7
10  5
*/