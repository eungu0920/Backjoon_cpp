#include<iostream>

using namespace std;

int K, N;
unsigned int ans;

int search(unsigned int left, unsigned int right, unsigned int LAN[]) {
    int cnt = 0;
    if(left > right) {
        return -1;
    }

    unsigned int mid = (left + right) / 2;

    for(int i = 0; i < K; i++) {
        cnt += LAN[i] / mid;
    }

    if(cnt >= N) {
        ans = max(mid, ans);
        return search(mid + 1, right, LAN);
    } else {
        return search(left, mid - 1, LAN);
    }
}

int main() {
    cin >> K >> N;
    
    unsigned int LAN[K];
    int sum = 0;

    for(int i = 0; i < K; i++) {
        cin >> LAN[i];
        sum += LAN[i];
    }

    int ave = sum / N;

    search(1, ave, LAN);

    cout << ans << endl;

    return 0;
}