// 비트 연산자
#include <iostream>
using namespace std;

int main()
{
	int A = 3; // 0011
	int B = 5; // 0101

	int C = A & B; // 0001
	int D = A | B; // 0111
	int E = A ^ B; // 0110

	// ~ : original -> -(original) - 1
	// int : 4byte -> 0000 0000 0000 0000
	// 가장 앞의 값은 부호를 나타냄
	// 따라서 3은 0000 0000 0000 0011
	// ~3은 1111 1111 1111 1100
	// 3 + -3 = 0 -> 위의 두개를 더해서 1111 1111 1111 1111 으로 나오는데 -0이라 한다
	// -0과 -0을 더하면 11111 1111 1111 1110이 나오면서 다른값이 나오는 문제가 발생한다.
	int F = ~A; // 1100 -> -4 
	int G = ~B; // 1010 -> -6

	int H = A >> 1; // 0001
	int I = A << 2; // 1100
	
	int original = 17;
	int a = 123456789;
	int b = 987654321;
	int c = original ^ a ^ b ^ b ^ a; // 35	

	return 0;
}