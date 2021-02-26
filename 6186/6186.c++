#include<iostream>
#include<string>
#include<queue>

using namespace std;

char map[100][100];
bool visit[100][100];

int R, C, result;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

// BFS
void bfs(int r, int c) {
    visit[r][c] = true;

    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if(map[nr][nc] == '#' && visit[nr][nc] == false) {
                    q.push({nr, nc});
                    visit[nr][nc] = true;
                }
            }
        }
    }
    
}

// DFS
void dfs(int r, int c) {
    visit[r][c] = true;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr >= 0 && nr < R && nc >= 0 && nc < C) {
            if(map[nr][nc] == '#' && visit[nr][nc] == false) {
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);

    for(int r = 0; r < R; r++) {
        string temp;
        cin >> temp;
        for(int c = 0; c < C; c++) {
            map[r][c] = temp[c];
        }
    }

    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(map[r][c] == '#' && visit[r][c] == false) {
                result++;
                /*
                BFS
                q.push({r, c});
                bfs(r, c);
                */

                // DFS
                dfs(r, c);
            }
        }
    }

    printf("%d\n", result);

    return 0;
}