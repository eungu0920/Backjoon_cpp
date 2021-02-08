#include<iostream>
#include<queue>

using namespace std;

int N, K;
int map[100001];
bool visit[100001];

int dx[3] = {1, -1, 2};

void bfs(int x) {
    queue<int> q;
    visit[x] = true;
    map[x] = 0;

    q.push(x);

    while(!q.empty()) {
        x = q.front();

        if(x == K)
            break;

        q.pop();

        for(int i = 0; i < 3; i++) {
            int nx = 0;
            if(dx[i] == 2) {
                nx = x * dx[i];
            } else {
                nx = x + dx[i];
            }

            if(nx >= 0 && nx < 100001) {
                if(visit[nx] == false) {
                    q.push(nx);
                    visit[nx] = true;
                    map[nx] = map[x] + 1;
                }
            }
        }

    }
}

int main() {
    cin >> N >> K;

    if(N >= K) {
        cout << N - K << endl;
    } else {
        bfs(N);
        cout << map[K] << endl;
    }

    return 0;
}