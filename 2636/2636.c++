#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int hours;
int counting;
int minimum = 0;

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
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            if(map[x][y] == 1) {
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(map[nx][ny] == 0 && visit[nx][ny] == true && map[x][y] == 1) {
                        // 공기층일때
                        map[x][y]--;
                        // 녹이고
                        break;
                        // 반복문 탈출
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while(true) {
        counting = 0;
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < M; y++) {
                if(map[x][y] == 1) {
                    counting++;
                }
            }
        }
        minimum = counting;

        memset(visit, false, sizeof(visit));
        q.push({0, 0});
        airBfs();
        meltingCheese();
        hours++;

        counting = 0;

        for(int x = 0; x < N; x++) {
            for(int y = 0; y < M; y++) {
                if(map[x][y] == 1) {
                    counting++;
                }
            }
        }
        
        if(counting == 0) {
            break;
        }

    }

    cout << hours << "\n" << minimum << "\n";

    return 0;
}