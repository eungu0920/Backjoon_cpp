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
        if(nx >= 0 && nx < R && ny >= 0 && ny < C) { // 범위 처리
            if(check[map[nx][ny]] == false) { // 알파벳이 사용되지 않았다면
                check[map[nx][ny]] = true; // 알파벳 체크
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
    // 첫번째 칸인 좌측 상단 칸의 알파벳 체크

    dfs(0, 0, 1);
    // 좌표값, 카운트값

    cout << result << endl;

    return 0;
}