/*
#include <iostream>
#include <queue> 
using namespace std;

int y;
int x;
int by;
int bx;

string MAP[5];

struct Node {
    int y; // y좌표 
    int x; // x좌표 
};

void bfs(int y, int x) {
    // #1. queue 준비
    queue<Node>q;
    q.push({ y, x });

    // #2. visited 준비
    int visited[5][5] = { 0, };
    visited[y][x] = 1; // 시작 노드 방문 기록 

    // #3. 방향 배열 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    // #4. BFS 동작 (flood fill) 
    while (!q.empty()) {
        // queue (대기열의) 맨 앞에 있는 노드를 추출 
        Node now = q.front();
        q.pop();

        // now로 부터 갈 수 있는 노드들을 확인하고, 그리고 queue에 삽입 
        // 갈 수 있는 방향 -> 문제에서 주어진다 -> 상하좌우로 퍼진다
        for (int i = 0; i < 4; i++) {
            // 다음 갈 수 있는 좌표를 일단 본다.
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // 범위 체크 무조건 #1 
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; // 여기는 못간다

            // (ny, nx) 이미 방문했거나, 방문이 예약된 상태라면 
            if (visited[ny][nx] != 0)
                continue;

            // if (내가 지금 갈려고하는 곳이 벽이라면)
            if (MAP[ny][nx] == '#')
                continue;

            // --- 내가 (ny, nx)를 갈 수 있다! 라는게 확정
            // 방문 기록 (예약)
            // 다음 좌표까지의 경로 = 현재 위치까지의 경로에서 +1번 더 퍼져나간 경로
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }

    // -- while이 끝나면 -- visited가 다 채워진 상태 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << visited[i][j] - 1 << " ";
        }
        cout << '\n';
    }
    cout << "정답 : " << visited[by][bx] - 1;
}

int main() {

    for (int i = 0; i < 5; i++) {
        cin >> MAP[i];
    }

    cin >> y >> x;
    // bfs(시작 노드)
    // bfs(시작 좌표) -> bfs(y, x); 

    cin >> by >> bx;

    bfs(y, x);
}
*/

/*
#include <iostream>
#include <queue> 
using namespace std;

int sy;
int sx;
int by;
int bx;
int my;
int mx;

string MAP[5];
int dist = 0;

struct Node {
    int y; // y좌표 
    int x; // x좌표 
};

void bfs(int y, int x, int dy, int dx) {
    // #1. queue 준비
    queue<Node>q;
    q.push({ y, x });

    // #2. visited 준비
    int visited[5][5] = { 0, };
    visited[y][x] = 1; // 시작 노드 방문 기록 

    // #3. 방향 배열 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    // #4. BFS 동작 (flood fill) 
    while (!q.empty()) {
        // queue (대기열의) 맨 앞에 있는 노드를 추출 
        Node now = q.front();
        q.pop();

        // now로 부터 갈 수 있는 노드들을 확인하고, 그리고 queue에 삽입 
        // 갈 수 있는 방향 -> 문제에서 주어진다 -> 상하좌우로 퍼진다
        for (int i = 0; i < 4; i++) {
            // 다음 갈 수 있는 좌표를 일단 본다.
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // 범위 체크 무조건 #1 
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; // 여기는 못간다

            // (ny, nx) 이미 방문했거나, 방문이 예약된 상태라면 
            if (visited[ny][nx] != 0)
                continue;

            // if (내가 지금 갈려고하는 곳이 벽이라면)
            if (MAP[ny][nx] == '#')
                continue;

            // --- 내가 (ny, nx)를 갈 수 있다! 라는게 확정
            // 방문 기록 (예약)
            // 다음 좌표까지의 경로 = 현재 위치까지의 경로에서 +1번 더 퍼져나간 경로
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }
    
    // -- while이 끝나면 -- visited가 다 채워진 상태
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << visited[i][j]-1 << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << "정답 : " << visited[by][bx] - 1;
    
    dist += visited[dy][dx] - 1;
}

void bfs2(int y, int x) {
    // #1. queue 준비
    queue<Node>q;
    q.push({ y, x });

    // #2. visited 준비
    int visited[5][5] = { 0, };
    visited[y][x] = 1; // 시작 노드 방문 기록 

    // #3. 방향 배열 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    // #4. BFS 동작 (flood fill) 
    while (!q.empty()) {
        // queue (대기열의) 맨 앞에 있는 노드를 추출 
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            // 다음 갈 수 있는 좌표를 일단 본다.
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            // 범위 체크 무조건 #1 
            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
                continue; // 여기는 못간다
            if (visited[ny][nx] != 0)
                continue;
            if (MAP[ny][nx] == '#')
                continue;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << visited[i][j] << " ";
        cout << '\n';
    }

    cout << visited[sy][sx] - 1 << '\n';
    cout << visited[by][bx] - 1 << '\n';

    // 무기 -> 캐릭터 
    dist += visited[sy][sx] - 1;
    // 무기 -> 보스
    dist += visited[by][bx] - 1;
}

int main() {

    for (int i = 0; i < 5; i++) {
        cin >> MAP[i];
    }

    cin >> sy >> sx;
    // bfs(시작 노드)
    // bfs(시작 좌표) -> bfs(y, x); 

    cin >> by >> bx;
    cin >> my >> mx;

    
    //bfs(y, x, my, mx);
    //bfs(my, mx, by, bx);
    

    bfs2(my, mx);

    cout << dist;
}
*/

/*
#include <iostream>
#include <queue> 
using namespace std;

int sy, sx;

string MAP[8] = {
    "####",
    "###_",
    "#___",
    "_###",
    "_###",
    "____",
    "##__",
    "#___"
};

struct Node {
    int y; // y좌표 
    int x; // x좌표 
};

// 단계별 floodfill 
//void bfs(int y, int x) {
//    // #1. queue 준비
//    queue<Node>q;
//    q.push({ y, x });
//
//// #2. visited 준비
//int visited[5][5] = { 0, };
//visited[y][x] = 1; // 시작 노드 방문 기록
//
//// #3. 방향 배열
//int ydir[] = { -1, 1, 0, 0 };
//int xdir[] = { 0, 0, -1, 1 };
//
//int day = 1;
//cout << "DAY #" << day << '\n';
//for (int i = 0; i < 5; i++) {
//    for (int j = 0; j < 5; j++) {
//        cout << visited[i][j];
//    }
//    cout << '\n';
//}
//
//while (!q.empty()) {
//    // 다음 날이 되었다!
//    day++;
//
//    // 지금 queue에서 오늘 날짜에 감염될 node 만큼만을 추출해서 기록
//    int cursize = q.size();
//    for (int j = 0; j < cursize; j++) {
//
//        Node now = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {
//            int ny = now.y + ydir[i];
//            int nx = now.x + xdir[i];
//
//            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
//                continue; //
//
//            if (visited[ny][nx] == 1)
//                continue;
//
//            visited[ny][nx] = 1;
//            q.push({ ny, nx });
//        }
//    }
//
//    cout << "DAY #" << day << '\n';
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << visited[i][j];
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}
//}


int cnt = 0;
// visited를 여러번의 flood fill에서 공유할수 있도록 함
int visited[8][8] = { 0, };

void bfs(int y, int x) {
    // #1. queue 준비
    queue<Node>q;
    q.push({ y, x });

    // #2. visited 준비
    visited[y][x] = 1; // 시작 노드 방문 기록 

    // #3. 방향 배열 
    int ydir[] = { -1, 1, 0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    while (!q.empty()) {

        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];

            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
                continue; // 

            if (visited[ny][nx] == 1)
                continue;

            // 연결된 섬이라면 -> 계속
            if (MAP[ny][nx] == '_')
                continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // 만약 이 위치가 섬이라면 && 아직 확인하지 않은 섬이라면
            if (MAP[i][j] == '#' && visited[i][j] == 0) {
                bfs(i, j);
                // 한번의 플러드필이 종료된다면 -> 하나의 연결된 섬을 찾았다!
                cnt++;
            }
        }
    }
    cout << cnt;
}
*/