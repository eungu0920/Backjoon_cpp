#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M, years;

int map[300][300];
bool visit[300][300];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(int i, int j) {
    visit[i][j] = true;
    q.push({i, j});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(visit[nx][ny] == false && map[nx][ny] > 0) {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

//분리된 빙산의 개수를 세는 함수
int countingIceberg() {
    int cnt = 0;

    memset(visit, false, sizeof(visit));

    for(int i = 1; i < N-1; i++) {
        for(int j = 1; j < M-1; j++) {
            // 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워지므로 그 다음 행, 열부터 탐색
            if(visit[i][j] == false && map[i][j] > 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

// 1년 후 빙산의 모습을 계산하는 함수
void deleteIceberg() {
    memset(visit, false, sizeof(visit));
    // 방문 초기화

    for(int x = 1; x < N-1; x++) {
        for(int y = 1; y < M-1; y++) {
            // 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워지므로 그 다음 행, 열부터 탐색
            if(map[x][y] > 0) {
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(map[nx][ny] == 0 && visit[nx][ny] == false && map[x][y] > 0) {
                            //4방향으로 탐색하면서 0이 있을 때마다 깎지만 map[x][y] 가 0이 되면 더이상 깎지 않는다.
                            map[x][y]--;
                        }
                    }
                }
                visit[x][y] = true;
                // 현재 깎은 빙산이 0이 되었을 때 다음 좌표에서 0으로 인식하고 깎지 않기 위해 방문처리를 한다.
            }
        }
    }

}

int main() {
    cin >> N >> M;

    // 빙산 입력
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while(true) {
        int result = countingIceberg();

        if(result > 1) {
            // 빙산의 개수가 두 덩어리 이상 일 때
            cout << years << "\n";
            break;
        } else if(result == 0) {
            // 빙산의 개수가 두 덩어리 이상으로 분리되지 않을 때
            cout << 0 << "\n";
            break;
        } else {
            // 계속 한 덩어리 일 때
            years++;
            // 년수를 올리고
            deleteIceberg();
            // 빙산 삭제 함수 실행
        }

    }

    return 0;
}