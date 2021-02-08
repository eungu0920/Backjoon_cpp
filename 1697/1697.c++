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

        if(x == K) // 동생의 위치를 만나는 경우 while 탈출
            break;

        q.pop();

        for(int i = 0; i < 3; i++) {
            int nx = 0;
            if(dx[i] == 2) { // 순간이동을 하는 경우
                nx = x * dx[i];
            } else { // 그냥 걷는 경우
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

    if(N >= K) { // 수빈이의 위치가 더 앞에 있는 경우 or 같은 자리인 때
        cout << N - K << endl;
    } else {
        bfs(N);
        cout << map[K] << endl;
    }

    return 0;
}