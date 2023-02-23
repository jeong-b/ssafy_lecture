#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		// reset
		int fee[4] = { 0 };
		int plan[12] = { 0 };
		int month[12] = { 0 };
		int charge = 0, temp1 = 0, temp2 = 0;
		int dToM, mToTM;

		// input
		for (int i = 0; i < 4; i++) cin >> fee[i];
		for (int i = 0; i < 12; i++) cin >> plan[i];

		// solve
		// #1. 각 요금 비교
		dToM = fee[1] / fee[0];
		if (fee[2] > fee[1] * 3) mToTM = -1;
		else mToTM = 1;

		// #2. 1일권 & 1달권으로 경제적 가격만들기
		for (int i = 0; i < 12; i++)
		{
			if (plan[i] == 0) continue;
			
			if (plan[i] <= dToM) month[i] = (plan[i] * fee[0]);
			else month[i] = fee[1];		
		}
		for (int i = 0; i < 12; i++) charge += month[i];

		// #3. 위의 과정 이후 3달권 가격으로 경제적으로 만들 수 있는지 확인
		if (mToTM == 1)
		{
			temp1 = charge;
			for (int i = 0; i < 10; i++)
			{
				int sum = month[i] + month[i + 1] + month[i + 2];

				if (sum > fee[2]) 
				{
					temp1 = temp1 - sum + fee[2];					
					i = i + 2;
				}
			}

			temp2 = charge;
			for (int i = 11; i >= 2; i--)
			{
				int sum = month[i] + month[i - 1] + month[i - 2];

				if (sum > fee[2])
				{
					temp2 = temp2 - sum + fee[2];
					i = i - 2;
				}
			}

			if (temp1 <= temp2) charge = temp1;
			else charge = temp2;
		}

		// #4. 위 가격을 1년권과 비교하기	
		if (charge > fee[3]) charge = fee[3];	

		// output
		cout << "#" << tc << " " << charge << "\n";
	}

	return 0;
}