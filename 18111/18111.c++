#include<iostream>

using namespace std;

int main() {
    int N, M, B;

    cin >> N >> M >> B;

    int map[N * M];
    int maxi = 0;
    int mini = 256;

    for(int i = 0; i < N * M; i++) {
        cin >> map[i];
        maxi = maxi > map[i] ? maxi : map[i];
        mini = mini > map[i] ? map[i] : mini;
    }

    int time, height, build, remove, leastTime, mostHeight;

    for(int i = mini; i <= maxi; i++) {
        // 높이의 최소값부터 최대값까지 탐색
        build = remove = 0;

        for(int j = 0; j < N * M; j++) {
            height = map[j] - i;
            if(height > 0) {
            // height가 0보다 크다면 height 만큼 블럭의 수를 제거해야 한다.
                remove += height;
            } else if(height < 0) {
            // 반대로 0보다 작다면 height 만큼 블럭의 수를 쌓아야 한다.
                build -= height;
            }
        }

        if(remove + B >= build) {
        // B(원래 가지고 있던 블럭의 수) + remove(제거하면서 나온 블럭의 수)가
        // build(쌓아야 하는 블럭의 개수)보다 클 작다면 블럭의 수가 부족하므로 건너뛴다
            time = remove * 2 + build;
            // 제거하는데 시간이 2초가 걸리므로 remove에 곱하기 2를한다.
            if(leastTime >= time) {
            // 걸린시간(time)보다 최소시간(leastTime)이 더 크다면 바꿔줌
                leastTime = time;
                mostHeight = i;
            } else if(i == mini) {
                leastTime = time;
                mostHeight = i;
            }
        }
    } 


    cout << leastTime << " " << mostHeight << endl;
}