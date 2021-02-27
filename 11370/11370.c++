#include<iostream>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int W, H;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    W = 1;
    H = 1;

    while(W != 0 && H != 0) {
        scanf("%d %d", &W, &H);
        char map[H][W];
        bool visit[H][W];

        memset(map, '.', sizeof(map));
        memset(visit, false, sizeof(visit));

        queue<pair<int, int>> q;

        for(int x = 0; x < H; x++) {
            string temp;
            cin >> temp;
            for(int y = 0; y < W; y++) {
                map[x][y] = temp[y];
                if(map[x][y] == 'S') {
                    q.push({x, y});
                    visit[x][y] = true;
                }
            }
        }

        //BFS
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if(map[nx][ny] == 'T' && visit[nx][ny] == false) {
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                        map[nx][ny] = 'S';
                    }
                }
            }

        }

        for(int x = 0; x < H; x++) {
            for(int y = 0; y < W; y++) {
                printf("%c", map[x][y]);
            }
            printf("\n");
        }


    }

    return 0;
}