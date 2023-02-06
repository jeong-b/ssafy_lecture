#include <iostream>
using namespace std;

void func(int a) {
  // 2. 기저 조건(끝낼 조건) : a가 10이 되면 중단
  if (a == 10)
  { // 끝내면서 처리
    cout << a << " ";
    return;
  }

  // 3-1. 기록 및 처리
  // 다음 함수로 가기 '전' <- 가면서 진행
  cout << a << " "; // 출력 : 0 , 2 3 4 5 6 7 8 9

  // 1. 재귀 기본 구조
  // 다음 함수로 가라
  func(a + 1);

  // 3-2. 기록 및 처리
  // 다음 함수를 갔다 온 후 <- 돌아오면서 진행
  cout << a << " "; // 출력 : 9 8 7 6 5 4 3 2 1
}

int main() {
  func(0);
  return 0;
}