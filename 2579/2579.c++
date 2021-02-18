#include<iostream>

using namespace std;

int arr[301];
int dp[301];

/*
문제 접근 방법 :
n번째 계단을 밟는 경우는 두가지 방법 밖에없다
1. n번째를 밟고 n-2번째 계단을 밟는 경우
2. n번째를 밟고, n-1번째와 n-3번째를 밟는 경우
문제에 나온 예로 6번째 계단을 밟는 경우에는
4번째 계단을 밟는 경우와 5, 3번째 계단을 밟는 경우로 나눌 수 있고
각각 또 4번째 계단을 밟는 경우는 2번째 계단을 밟는 경우와
3, 1번째 계단을 밟는 경우로 나눌 수 있으며
5, 3번째 계단을 밟는 경우는 1번째 계단을 밟는 경우 또는
2번째 계단을 밟는 경우로 나눌 수 있다.
*/

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

    for(int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }

    cout << dp[N] << "\n";

    return 0;
}