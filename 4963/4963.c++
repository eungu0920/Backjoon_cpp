#include<iostream>
#include<queue>

using namespace std;

#define MAX 50

// 섬의 개수

int w, h;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
            
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if(map[nx][ny] == 1 && visit[nx][ny] == false) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
        }
    }
}

void dfs(int x, int y) {
    visit[x][y] = true;
    
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if(map[nx][ny] == 1 && visit[nx][ny] == false) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    while(true) {
        fill(map[0], map[50], 0);
        fill(visit[0], visit[50], 0);

        cin >> w >> h;

        if(w == 0 && h == 0) {
            break;
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        int cnt = 0;

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
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