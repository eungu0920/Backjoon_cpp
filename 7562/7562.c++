#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[300][300];
bool visit[300][300];
int l;
int X, Y;

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
// 나이트의 이동 방법

void bfs(queue<pair<int, int>> q) {
    int x, y;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visit[x][y] = true;

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < l && ny >= 0 && ny < l) {
                if(visit[nx][ny] == false && map[nx][ny] == 0) {
                    q.push({nx, ny});
                    map[nx][ny] = map[x][y] + 1;
                    if(nx == X && ny == Y) {
                        // 나이트가 이동하려는 칸에 도착했을 때
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int testCase;
    cin >> testCase;

    for(int t = 0; t < testCase; t++) {
        cin >> l;

        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        // 테스트 케이스를 한번 수행할 때마다 초기화

        queue<pair<int, int>> q;

        cin >> X >> Y;
        // 나이트의 시작 위치

        q.push({X, Y});
        // 나이트의 시작 위치를 큐에 넣음

        cin >> X >> Y;
        // 나이트가 이동하려는 위치

        bfs(q);
        // bfs수행

        cout << map[X][Y] << "\n";
    
    }
    return 0;
}