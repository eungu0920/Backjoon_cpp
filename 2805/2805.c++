#include<iostream>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    int tree[N];
    int maxTree = 0;

    for(int i = 0; i < N; i++) {
        cin >> tree[i];
        maxTree = maxTree < tree[i] ? tree[i] : maxTree;
    }

    int left = 1;
    int right = maxTree;
    long long int cnt;
    int mid;
    int result = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        cnt = 0;
        
        for(int i = 0; i < N; i++) {
            if(mid <= tree[i]) {
                cnt += tree[i] - mid;
            }
        }

        if(cnt >= M) {
            left = mid + 1;
            result = max(result, mid);
        } else if(cnt < M) {
            right = mid - 1;
        }


    }

    cout << result << endl;

    return 0;
}