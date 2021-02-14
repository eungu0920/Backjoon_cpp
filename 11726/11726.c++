#include<iostream>

using namespace std;

int dp[1001];

int main() {
    int n;

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
        // dp(n) = dp(n-1) + dp(n-2)로 분할하여 계산
    }

    cout << dp[n]<< endl;
 
    return 0;
}