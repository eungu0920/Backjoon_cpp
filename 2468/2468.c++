#include<iostream>

using namespace std;

#define MAX 100

// 안전 영역

int map[MAX][MAX];
bool visit[MAX][MAX];
bool check[MAX][MAX];

int N;
int max_value = 0;
int max_height = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visit[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(visit[nx][ny] == false) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            max_height = max_height < map[i][j] ? map[i][j] : max_height;
        }
    }

    for(int i = 1; i <= max_height; i++) {
        fill(visit[0], visit[N], false);

        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(map[j][k] <= i) {
                    visit[j][k] = true;
                }
            }
        }

        int cnt = 0;

        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(visit[j][k] == false) {
                    dfs(j, k);
                    cnt++;
                }
            }
        }
        max_value = max_value < cnt ? cnt : max_value;

    }
    
    if(max_value == 0) {
        max_value = 1;
    }

    cout << max_value << endl;

    return 0;
}