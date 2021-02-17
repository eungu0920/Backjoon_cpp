#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int testCase;

    cin >> testCase;

    for(int t = 0; t < testCase; t++) {
        queue<pair<int, int>> q;

        int N, M;
        cin >> N >> M;

        int arr[N]; // 중요도 배열

        for(int i = 0; i < N; i++) {
            int importance;
            cin >> importance;
            arr[i] = importance;

            q.push({i, importance});
        }

        sort(arr, arr + N, compare);
        // 중요도를 내림차순으로 정렬

        int cnt = 0;
        int pt = 0; // 중요도 순으로 프린트하기 위함

        while(!q.empty()) {
            int x, y;
            x = q.front().first;
            y = q.front().second;
        
            if(y == arr[pt]) {
                // 큐의 첫번째와 중요도가 일치하면
                q.pop();
                cnt++; // 프린트를 수행한 것이므로 카운트 증가
                pt++;
                if(x == M) {
                    // 프린트 한 것의 번호와 궁금한 것의 번호가 일치하면 중지
                    break;
                }
            } else {
                // 중요도가 낮아 프린트하지 못했다면 큐의 뒤로 다시 배치
                q.pop();
                q.push({x, y});
            }

        }

        cout << cnt << endl;

    }

    return 0;
}