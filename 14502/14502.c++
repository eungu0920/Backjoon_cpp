#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int maximum = 0;

int map[8][8];
int temp[8][8];
bool visit[8][8];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;
queue<pair<int, int>> tempQueue;

void bfs() {
    tempQueue = q;
    int x, y;
    x = tempQueue.front().first;
    y = tempQueue.front().second; 
    visit[x][y] = true;
    while(!tempQueue.empty()) {
        x = tempQueue.front().first;
        y = tempQueue.front().second;
        tempQueue.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(visit[nx][ny] == false && temp[nx][ny] == 0) {
                    // temp배열에서 벽 또는 바이러스가 없을 경우
                    tempQueue.push({nx, ny});
                    visit[nx][ny] = true;
                    temp[nx][ny] = 2;
                    // 바이러스가 퍼짐
                }
            }
        }
    }

}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                q.push({i, j});
                // 바이러스가 있는 위치는 바로 큐에 넣음
            }
        }
    }

    // 벽 세우기 모든 경우 탐색(브루트포스)
    for(int a = 0; a < N; a++) {
        for(int b = 0; b < M; b++) {
            if(map[a][b] == 0) {
                map[a][b] = 1;

                for(int x = a; x < N; x++) {
                    for(int y = 0; y < M; y++) {
                        if(map[x][y] == 0) {
                            map[x][y] = 1;

                            for(int i = x; i < N; i++) {
                                for(int j = 0; j < M; j++) {
                                    if(map[i][j] == 0) {
                                        map[i][j] = 1;
                                        memcpy(temp, map, sizeof(map));
                                        // 각 경우마다 temp에 복사를 해서 temp배열로 bfs를 수행함
                                        memset(visit, false, sizeof(visit));
                                        // bfs수행을 위한 방문 초기화
                                        bfs();
                                        int cnt = 0;
                                        for(int c = 0; c < N; c++) {
                                            for(int d = 0; d < M; d++) {
                                                if(temp[c][d] == 0) {
                                                    cnt++;
                                                    // 안전 영역의 크기를 구함
                                                }
                                            }
                                        }
                                        maximum = maximum < cnt ? cnt : maximum;
                                        // 안전영역의 최댓값
                                        cnt = 0;

                                        map[i][j] = 0;
                                    }

                                }
                            }

                            map[x][y] = 0;
                        }
                    }
                }

                map[a][b] = 0;
            }
        }
    }

    printf("%d\n", maximum);

    return 0;
}