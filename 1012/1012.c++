#include<iostream>
#include<queue>

using namespace std;

#define MAX 50

// 유기농 배추

int M, N, K;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) {
                continue;
            }

            if(map[nx][ny] == 1 && visit[nx][ny] == false) {
                visit[nx][ny] = true;
                q.push({nx, ny});
            }

        }
    }
}

int main() {
    int test_case;

    cin >> test_case;

    for(int T = 0; T < test_case; T++) {
        int cnt = 0;
        cin >> M >> N >> K;
        fill(map[0], map[M], 0);
        fill(visit[0], visit[M], 0);
        
        for(int i = 0; i < K; i++) {
            int u, v;
            cin >> u >> v;

            map[u][v] = 1;
        }

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++ ) {
                if(map[i][j] == 1 && visit[i][j] == false) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;

    }

    return 0;
}