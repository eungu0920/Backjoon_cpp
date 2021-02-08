#include<iostream>
#include<queue>

using namespace std;

#define MAX 1000

// 토마토

int map[MAX][MAX];
bool visit[MAX][MAX];

queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int M, N;
int result = 0;

void bfs() {
    int x, y;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visit[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(map[nx][ny] == 0 && visit[nx][ny] == false) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;

                    map[nx][ny] = map[x][y] + 1;
                    result = map[nx][ny];
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                result = -1;
            }
        }
    }

    if(result > 0) {
        cout << result - 1 << endl;
    } else {
        cout << result << endl;
    }
}