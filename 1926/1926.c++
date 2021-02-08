#include<iostream>
#include<queue>

using namespace std;

#define MAX 500

int map[MAX][MAX];
bool visit[MAX][MAX];

int N, M;
int cnt = 0;
int total = 0;
int result = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


//DFS
void dfs(int x, int y) {
    visit[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(visit[nx][ny] == false && map[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
}

//BFS
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    cnt = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(visit[nx][ny] == false && map[nx][ny] == 1) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                    cnt++;
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
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 1 && visit[i][j] == false) {
                cnt = 0;
                bfs(i, j);
                total++;
                result = cnt > result ? cnt : result;
            }
        }
    }

    cout << total << endl << result << endl;

    return 0;
}