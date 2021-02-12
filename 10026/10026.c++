#include<iostream>
#include<queue>
#include<string>

using namespace std;

char map[100][100];
bool visit[100][100];
bool visitColor[100][100];

int N;
int colorWeak = 0;
int normal = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    // 정상일 때의 dfs탐색
    visit[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            // 각각 현재의 색과 다음의 탐색하려는 색깔의 색이 일치할 때 다음 탐색을 시작한다.
            if(map[x][y] == 'R' && map[nx][ny] == 'R' && visit[nx][ny] == false) {
                dfs(nx, ny);
            } else if(map[x][y] == 'G' && map[nx][ny] == 'G' && visit[nx][ny] == false) {
                dfs(nx, ny);
            } else if(map[x][y] == 'B' && map[nx][ny] == 'B' && visit[nx][ny] == false) {
                dfs(nx, ny);
            }
        }
    }
}

void dfsColor(int x, int y) {
    // 색약이 있을 때의 dfs탐색
    visitColor[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            // 적색과 녹색의 색이 동일하다고 느끼므로 다음과 같이 탐색을 실행한다.
            if((map[x][y] == 'R' || map[x][y] == 'G')
                && (map[nx][ny] == 'R' || map[nx][ny] == 'G')
                    && visitColor[nx][ny] == false)
            {
                dfsColor(nx, ny);
            } else if(map[x][y] == 'B' && map[nx][ny] == 'B' && visitColor[nx][ny] == false) {
                dfsColor(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < N; j++) {
            map[i][j] = temp[j];
        }

    }

    // 탐색을 다르게 하는 두개의 dfs함수를 만들어 실행하였다.
    // 한개로 바꿀 수 있는 방법이 있을까?
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visit[i][j] == false) {
                normal++;
                dfs(i, j);
            }
            if(visitColor[i][j] == false) {
                colorWeak++;
                dfsColor(i, j);
            }
        }
    }

    printf("%d %d\n", normal, colorWeak);

    return 0;
}