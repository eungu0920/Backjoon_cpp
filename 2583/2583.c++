#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX 100

// 영역 구하기

bool visit[MAX][MAX];
vector<int> v;

int M, N, K;
int cnt = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visit[x][y] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(visit[nx][ny] == false) {
                dfs(nx, ny);
            }
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    cnt = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(visit[nx][ny] == false) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int x = a; x < c; x++) {
            for(int y = b; y < d; y++) {
                visit[x][y] = true;
            }
        }
    }

    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            if(visit[x][y] == false) {
                cnt = 0;
                bfs(x, y);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

    return 0;
}