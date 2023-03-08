#include <iostream>
using namespace std;

void func(int a) {
  // 2. 기저 조건
  if (a > 2) return;

  // 3. 기록 및 처리
  cout << a << " "; // 출력 : 0 1 2 2 1 2 2

  // 1. 재귀 기본 구조
  func(a + 1);
  func(a + 1);

}

int main() {
  func(0);
  return 0;
}