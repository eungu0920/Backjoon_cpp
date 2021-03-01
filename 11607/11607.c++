#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n, m;

int map[500][500];
bool visit[500][500];
int result[500][500];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            // 각 칸마다 칸에 써져있는 수 만큼 이동할 수 있으므로 칸의 수만큼 곱해준다.
            int nx = x + (dx[i] * map[x][y]);
            int ny = y + (dy[i] * map[x][y]);
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(visit[nx][ny] == false) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                    result[nx][ny] = result[x][y] + 1;
                    // 이동거리 수를 구해야 하므로 1씩 더해줌
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int x = 0; x < n; x++) {
        string temp;
        cin >> temp;
        for(int y = 0; y < m; y++) {
            map[x][y] = temp[y] - '0';
        }
    }

    q.push({0, 0});
    visit[0][0] = true;

    bfs();

    if(result[n-1][m-1] == 0) {
        // 만약 도달하지 못했다면
        printf("IMPOSSIBLE\n");
    } else {
        // 아니라면 시작지점부터 끝지점까지의 이동횟수의 최솟값을 출력
        printf("%d\n", result[n-1][m-1]);
    }

    return 0;
}