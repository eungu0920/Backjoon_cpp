#include<iostream>
#include<string>
#include<queue>
#include<tuple>

using namespace std;

#define MAX 1001

int map[MAX][MAX];
int visit[MAX][MAX][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

int bfs() {
    queue<tuple<int, int, int>> q;
    // x좌표, y좌표, 벽을 뚫을 수 있는 횟수

    int x, y, check;
    q.push(make_tuple(1, 1, 1));
    visit[1][1][1] = 1;

    while(!q.empty()) {
        tie(x, y, check) = q.front();

        q.pop();

        if(x == N && y == M) {
            // 목표위치에 도달하면 값을 리턴
            return visit[x][y][check];
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx > 0 && nx <= N && ny > 0 && ny <= M) {
                if(map[nx][ny] == 1 && check) {
                    // 벽이 있고 벽을 아직 안뚫었을 때.
                    visit[nx][ny][check - 1] = visit[x][y][check] + 1;
                    q.push(make_tuple(nx, ny, check - 1));
                }
                if(map[nx][ny] == 0 && visit[nx][ny][check] == 0) { 
                    // 벽이 없고, 방문하지 않았을 때.
                    visit[nx][ny][check] = visit[x][y][check] + 1;
                    q.push(make_tuple(nx, ny, check));
                }
            }
        }
    }
    return -1;
    // 목표위치에 도달하지 못했다면 -1을 리턴.
}

int main() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;
        for(int j = 1; j <= M; j++) {
            map[i][j] = temp[j - 1] - '0';
        }
    }
    
    cout << bfs() << endl;

    return 0;
}