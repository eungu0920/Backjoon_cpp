#include<iostream>
#include<queue>

using namespace std;

int stairs[1000001];
bool visit[1000001];

int F, S, G;
// 층수, 시작층, 도착층
int upDown[2];
// 위, 아래
queue<int> q;

void bfs() {
    q.push(S);
    visit[S] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == G) {
            // x가 도착층과 같다면
            break;
        }

        for(int i = 0; i < 2; i++) {
            int nx = x + upDown[i];
            if(nx > 0 && nx <= F) {
                // nx가 1층에서 F(총 층수)층 사이일 때만 실행
                if(visit[nx] == false) {
                    stairs[nx] = stairs[x] + 1;
                    visit[nx] = true;
                    q.push(nx);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &upDown[0], &upDown[1]);

    upDown[1] *= -1;
    // 아래층으로 내려가는걸 음수로 변경

    if(S == G) {
        // 시작층과 도착층이 같을 때
        printf("0\n");
    } else {
        bfs();

        if(stairs[G] == 0) {
            // 층이 탐색되어있지 않다면
            printf("use the stairs\n");
        } else {
            printf("%d\n", stairs[G]);
        }
    }
    
    return 0;
}