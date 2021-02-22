#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M, hours;
int counting = 1;

int map[100][100];
bool visit[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void airBfs() {
    int x = q.front().first;
    int y = q.front().second;
    visit[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(map[nx][ny] == 0 && visit[nx][ny] == false) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }
    }


}

void meltingCheese() {
    for(int x = 1; x < N-1; x++) {
        for(int y = 1; y < M-1; y++) {
            if(map[x][y] == 1) {
                int cnt = 0;
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(visit[nx][ny] == true) {
                        // 치즈 옆에 공기가 접촉하면
                        cnt++;
                    }

                    if(cnt > 1) {
                        // 접촉하는 변이 2개 이상일 때
                        map[x][y]--;
                        break;
                    }
                }
            }
        }
    }
}

int countingCheese(int counting) {
    for(int x = 1; x < N-1; x++) {
        for(int y = 1; y < M-1; y++) {
            if(map[x][y] == 1) {
                counting++;
            }
        }
    }

    return counting;
}

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while(counting != 0) {
        counting = 0;

        memset(visit, false, sizeof(visit));
        q.push({0, 0});
        airBfs();
        meltingCheese();
        counting = countingCheese(counting);
        hours++;
    }

    printf("%d\n", hours);

    return 0;
}