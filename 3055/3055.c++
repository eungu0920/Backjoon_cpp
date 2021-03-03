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
int xR, yR;

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
                    if(visit[nx][ny] == false && map[nx][ny] != 'D') {
                        map[nx][ny] = '*';
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                } else {
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
                q.push({x, y});
                visit[x][y] = true;
            } else if(map[x][y] == 'S') {
                xS = x;
                yS = y;
                visit[x][y] = true;
            } else if(map[x][y] == 'X') {
                visit[x][y] = true;
            } else if(map[x][y] == 'D') {
                xR = x;
                yR = y;
            }
        }
    }

    q.push({xS, yS});

    bfs();


    for(int x = 0; x < R; x++) {
        for(int y = 0; y < C; y++) {
            printf("%d ", result[x][y]);
        }
        printf("\n");
    }

    for(int x = 0; x < R; x++) {
        for(int y = 0; y < C; y++) {
            printf("%c ", map[x][y]);
        }
        printf("\n");
    }

    if(result[xR][yR] == 0) {
        printf("KAKTUS\n");
    } else {
        printf("%d\n", result[xR][yR]);
    }


    return 0;
}