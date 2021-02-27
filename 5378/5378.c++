#include<iostream>
#include<string>
#include<cstring>

using namespace std;

/*
사각형 배열에서 대각선으로 두방향으로 갈 수 있다고 추가하여 육각형을 만들었다.
원래 문제에서는 사각형이 45도 정도 기울어져있어 검정색은 왼쪽 위에부터 오른쪽 아래,
흰색은 오른쪽 위부터 왼쪽 아래까지 이어지는 돌을 놓는것이 목표이다.
편한 탐색을 위해 검정색은 위에서 아래, 흰색은 왼쪽에서 오른쪽으로
이어지면 이길 수 있게 설정해뒀다.
*/

char map[100][100];
bool visit[100][100];

int n, testCase;

// 6ways 8방향이 아닌 6방향으로만 이동가능(6각형) + 대각선 오른쪽 위와 왼쪽 아래 추가.
// 왼쪽 위와 오른쪽 아래로는 불가능
int dx[6] = {1, -1, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, -1, 1};

// Black stones DFS
void dfsBlack(int x, int y, bool data[]) {
    visit[x][y] = true;
    if(x == 0) {
        // 위에 도착 했디면
        data[0] = true;
    } else if(x == n-1) {
        // 아래에 도착 했다면
        data[1] = true;
    }

    for(int i = 0; i < 6; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny <n) {
            if(map[nx][ny] == 'B' && visit[nx][ny] == false) {
                dfsBlack(nx, ny, data);
            }
        }
    }
}

// White stones DFS
void dfsWhite(int x, int y, bool data[]) {
    visit[x][y] = true;
    if(y == 0) {
        // 왼쪽에 도착했다면
        data[0] = true;
    } else if(y == n-1) {
        // 오른쪽에 도착했다면
        data[1] = true;
    }

    for(int i = 0; i < 6; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny <n) {
            if(map[nx][ny] == 'W' && visit[nx][ny] == false) {
                dfsWhite(nx, ny, data);
            }
        }
    }
}

int main() {
    scanf("%d", &testCase);

    for(int t = 0; t < testCase; t++) {
        // 테스트 케이스 수행시마다 모든 배열 초기화
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        
        bool resultBlack = false;
        bool resultWhite = false;
        // 검정색은 위에부터 아래까지 연결이 되면 true
        // 흰색은 오른쪽에서 왼쪽으로 연결이 되면 true

        scanf("%d", &n);

        for(int x = 0; x < n; x++) {
            string temp;
            cin >> temp;
            for(int y = 0; y < n; y++) {
                map[x][y] = temp[y];
            }
        }

        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(visit[x][y] == false && map[x][y] == 'B') {
                    bool black[2] = {false, false};
                    // 위쪽이 연결이 되면 첫번째 배열 true, 아래쪽이 연결되면 두번째 배열 true
                    // 탐색시마다 초기화
                    dfsBlack(x, y, black);
                    if(black[0] == true && black[1] == true) {
                        // 둘다 연결이 되어있다면
                        resultBlack = true;
                    }
                } else if(visit[x][y] == false && map[x][y] == 'W') {
                    // 흰색도 마찬가지로 수행
                    bool white[2] = {false, false};
                    dfsWhite(x, y, white);
                    if(white[0] == true && white[1] == true) {
                        resultWhite = true;
                    }
                }
            }
        }

        if(resultBlack == true && resultWhite != true) {
            // 검정색만 연결되어 있다면
            printf("Black wins\n");
        } else if(resultBlack != true && resultWhite == true) {
            // 흰색만 연결되어 있다면
            printf("White wins\n");
        } else {
            // 둘다 연결 되어있거나 아니라면
            printf("Not finished\n");
        }
    }

    return 0;
}