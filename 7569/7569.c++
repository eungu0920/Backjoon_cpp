#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

#define MAX 100

int map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int M, N, H;
int result = 0;

queue<tuple<int, int, int>> q;

void bfs() {
    int x, y, z;

    while(!q.empty()) {
        tie(z, y, x) = q.front();

        q.pop();
        visit[z][y][x] = true;

        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
                if(visit[nz][ny][nx] == false && map[nz][ny][nx] == 0) {
                    q.push(make_tuple(nz, ny, nx));
                    visit[nz][ny][nx] = true;
                    map[nz][ny][nx] = map[z][y][x] + 1;
                    result = map[nz][ny][nx];
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    bfs();

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(map[i][j][k] == 0) {
                    result = -1;
                }
            }
        }
    }

    if(result > 0) {
        cout << result - 1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}