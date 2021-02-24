#include<iostream>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

char map[50][50];
int map_search[50][50];
bool visit[50][50];
bool visit_search[50][50];

int N, M;
int result;
int maxi;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(int x, int y) {
    result = 0;
    visit_search[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(map[nx][ny] == 'L' && visit_search[nx][ny] == false) {
                    // 육지이면서 방문하지 않았을 때 탐색 실행
                    q.push({nx, ny});
                    visit_search[nx][ny] = true;
                    map_search[nx][ny] = map_search[x][y] + 1;

                    if(map_search[nx][ny] > result) {
                        result = map_search[nx][ny];
                        // 이동하는 데 있어 가장 긴 시간이 걸리는 두 곳의 거리 최단거리 저장
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int x = 0; x < N; x++) {
        string temp;
        cin >> temp;
        for(int y = 0; y < M; y++) {
            map[x][y] = temp[y];
            if(map[x][y] == 'W') {
                // 바다 일 때 방문표시
                visit[x][y] = true;
            }
        }
    }


    // 완전탐색
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            if(map[x][y] == 'L') {
                // L인 경우 bfs탐색을 실행하여 각각 초기화 해준 후 최단거리를 구해낸다.
                memcpy(visit_search, visit, sizeof(visit)); // 바다를 표시해준 배열을 복사해줌
                memset(map_search, 0, sizeof(map_search));  // 최단거리 값을 구하기 위한 배열, bfs탐색을 위해 0으로 초기화
                q.push({x, y});
                bfs(x, y);
                maxi = result > maxi ? result : maxi;
                // 육지 두 곳의 최단거리중 가장 큰 값을 저장한다.
            }
        }
    }

    cout << maxi << "\n";

    return 0;
}