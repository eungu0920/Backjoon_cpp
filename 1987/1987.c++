#include<iostream>
#include<string>

using namespace std;

int map[20][20];
bool check[26];

int R, C;
int result = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int cnt) {

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if(check[map[nx][ny]] == false) {
                check[map[nx][ny]] = true;
                dfs(nx, ny, cnt + 1);
                check[map[nx][ny]] = false;
            }
        }
    }

    result = max(result, cnt);
}

int main() {
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < C; j++) {
            map[i][j] = temp[j] - 'A';
        }
    }
    check[map[0][0]] = true;
    dfs(0, 0, 1);

    cout << result << endl;

}