#include<iostream>
#include<string>
#include<queue>

using namespace std;

// 메모리 초과 발생함 답은 제대로 나오는 것 같음.

char map[1000][1000];
bool visit[1000][1000];
int result[1000][1000];

int N;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

queue<pair<int, int>> q;

void bfs() {
    int x, y;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < N && ny < N) {
                if(visit[nx][ny] == false) {
                    q.push({nx, ny});
                    if(nx > 0 && ny > 0) {
                        result[nx][ny] = result[nx][ny-1] + result[nx-1][ny];
                    } else if(nx == 0) {
                        result[nx][ny] = result[nx][ny-1];
                    } else {//(ny == 0) 
                        result[nx][ny] = result[nx-1][ny];
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int x = 0; x < N; x++) {
        string temp;
        cin >> temp;
        for(int y = 0; y < N; y++) {
            map[x][y] = temp[y];
            if(map[x][y] == '#') {
                visit[x][y] = true;
            }
        }
    }

    result[0][0] = 1;
    q.push({0, 0});
    bfs();

    if(result[N-1][N-1] == 0) {
        printf("THE GAME IS A LIE\n");
    } else {
        printf("%d\n", result[N-1][N-1]);
    }

    return 0;
}