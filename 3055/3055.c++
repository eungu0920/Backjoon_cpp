#include<iostream>
#include<string>
#include<queue>

using namespace std;

char map[50][50];
bool visit[50][50];
int result[50][50];

queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int R, C;

int xS, yS; // 임시 저장공간 큐의 맨 뒤에 S를 넣기 위함
int xR, yR; // 결과값을 위한 임시 저장 공간 결과를 출력할 때 사용

void bfs() {
    int x, y;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(map[x][y] == '*') {
                    // 물이 있는 칸인 경우
                    if(visit[nx][ny] == false && map[nx][ny] != 'D') {
                        map[nx][ny] = '*';
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                } else {
                    // 고슴도치가 이동한 칸인 경우
                    if(visit[nx][ny] == false) {
                        map[nx][ny] = 'S';
                        result[nx][ny] = result[x][y] + 1;
                        visit[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);

    for(int x = 0; x < R; x++) {
        string temp;
        cin >> temp;
        for(int y = 0; y < C; y++) {
            map[x][y] = temp[y];
            if(map[x][y] == '*') {
                // 물이 있는 칸일 때 큐에 넣음
                q.push({x, y});
                visit[x][y] = true;
            } else if(map[x][y] == 'S') {
                // 고슴도치가 있는 칸일 경우 바로 큐에 넣지 않고 임시저장해둠
                xS = x;
                yS = y;
                visit[x][y] = true;
            } else if(map[x][y] == 'X') {
                // 돌이 있는 경우 
                visit[x][y] = true;
            } else if(map[x][y] == 'D') {
                // 비버굴의 위치를 저장
                xR = x;
                yR = y;
            }
        }
    }

    // 큐에 물이 있는 공간의 위치를 전부 넣어둔 후 고슴도치의 위치를 큐에 넣어준다.
    q.push({xS, yS});

    bfs();

    if(result[xR][yR] == 0) {
        printf("KAKTUS\n");
    } else {
        printf("%d\n", result[xR][yR]);
    }

    return 0;
}