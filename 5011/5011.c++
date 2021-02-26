#include<iostream>
#include<string>
#include<queue>

using namespace std;

/* 
    1시도 메모리 초과 발생함 답은 제대로 나오는 것 같음.
    2시도 bool 타입을 제거 했음에도 메모리 초과 발생
    3시도 queue를 쓰지 않고 해야할 것 같음. Dynamic Programming을 해야할 것 같다.
    4시도 영어 문제라 꼼꼼히 읽지 못하였었다. 빠진부분을 추가함.
    5시도 영어 해석이 부족했던 것 같다. modulo : 나머지연산
    영어문제는 두번 세번 꼼꼼히 읽자.
    2번 틀렸을 걸 4번이나 틀렸다.
*/

const int MOD = INT_MAX;
typedef long long ll;

char map[1000][1000];
bool visit[1000][1000];
ll result[1000][1000];

int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void bfs(int x, int y) {
    visit[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(map[nx][ny] != '#' && visit[nx][ny] == false) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                    map[nx][ny] = 'C';
                    /*
                    .에서 C로 바꾸는 이유는 맨 마지막 칸이 C일때는
                    마지막 칸에 도달할 수 있으므로 결과값 또는 'THE GAME ...'을 출력 할 수 있다.
                    마지막칸이 C가 아닐경우 'INCONCEIVABLE'을 출력하면 된다.
                    */
                
                }
            }
                
            
        }
    }
}

void bfs_Robots() {
    q.push({0,0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < N && ny < N) {
                if(map[nx][ny] != '#') {
                    if(nx == 0) {
                        result[nx][ny] = result[nx][ny-1] % MOD;
                    } else if(ny == 0) {
                        result[nx][ny] = result[nx-1][ny] % MOD;
                    } else {
                        result[nx][ny] = (result[nx-1][ny] + result[nx][ny-1]) % MOD;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int x = 0; x < N; x++) {
        string temp;
        cin >> temp;
        for(int y = 0; y < N; y++) {
            map[x][y] = temp[y];
        }
    }

    q.push({0, 0});
    bfs(0, 0);
    
    /*
    위쪽과 아래쪽 두가지 방법으로만 목적지에 도달해야 한다.
    확인하려는 위치를 몇가지 방법으로 갈 수 있는지 알고 싶은 경우
    바로 위쪽 위치의 갈 수 있는 방법과 왼쪽 위치의 갈 수 있는 방법을 더하면 된다.
    결과값을 2^31 - 1로 나눈 나머지 값을 도출하라 했으므로 나머지 연산을 한다.
    */

    result[0][0] = 1;   // 시작 위치에 갈 수 있는 방법은 한가지 뿐이다.

    bfs_Robots();

/*
    //  경우의 수 계산 시작
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            if(map[x][y] != '#') {
                // 벽을 통과할 수 없으므로 벽이 아닐때만 실행한다.
                if(x == 0 && y == 0) { continue; };
                // 0, 0의 위치일 경우 바로 다음 탐색으로 넘어감

                if(x == 0) {    // x가 0인 경우 시작위치에서 오른쪽으로만 갔으므로 바로 왼쪽의 경우의 수와 동일하다.
                    result[x][y] = result[x][y-1] % MOD;
                } else if(y == 0) { //  y가 0인 경우 시작위치에서 아래쪽으로만 갔으므로 바로 위쪽의 경우의 수와 동일하다.
                    result[x][y] = result[x-1][y] % MOD;
                } else {    //  x와 y가 둘다 0이 아닌 경우 바로 위쪽의 경우의 수와 왼쪽의 경우의 수를 더해준다.
                    result[x][y] = (result[x][y-1] + result[x-1][y]) % MOD;
                }
            }
        }
    }
*/

    if(result[N-1][N-1] == 0 && map[N-1][N-1] == 'C') {
        /*
        마지막 칸의 값이 0인 경우 와 동시에 map의 마지막 값이 C인 경우
        4방향 탐색으로는 도달할 수 있지만 2방향(오른쪽, 아래)방향으로는 도달할 수 없는 경우이다.
        */
        printf("THE GAME IS A LIE\n");
    } else if(map[N-1][N-1] == 'C') {
        // 2방향으로만 갈 수 있는 경우 경우의 수 결과값 출력
        printf("%lld\n", result[N-1][N-1]);
    } else {
        // 벽으로 막혀있어 4방향으로도 갈 수 없다면
        printf("INCONCEIVABLE\n");
    }

    return 0;
}