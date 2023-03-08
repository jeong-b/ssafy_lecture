/* Direction Array - 방향 배열*/
#include<iostream>
using namespace std;

int main() {
    // 방향 배열
    int M[3][5] = { 0, };
    int row, col;
    cin >> row >> col;
        //  0      1

    //M[row + -1][col + 0] = 1;//상
    //M[row + 1][col + 0] = 1;//하
    //M[row + 0][col + -1] = 1;//좌
    //M[row + 0][col + 1] = 1;//우

            //   상 하 좌 우
    int dr[4] = {-1, 1, 0, 0}; // row쪽에 더해질 값
    int dc[4] = { 0, 0,-1, 1}; // col쪽에 더해질 값

    for (int i = 0; i < 4; i++)
    {
        int nr = row + dr[i]; // row에서 i번째 방향
        int nc = col + dc[i]; // col에서 i번째 방향
        //M[row + ? ][col + ? ] = 1

        //원하는 범위 바깥의 좌표가 계산되면 무시
        if (0 > nr || 0 > nc || nr >= 3 || nc >= 5) continue; 
        
        M[nr][nc] = 1;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << M[i][j];
        cout << "\n";
    }

    return 0;    
}