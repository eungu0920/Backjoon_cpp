#include<iostream>
#include<algorithm>

using namespace std;

// 신입 사원

int main() {
    int test_case;
    cin >> test_case;

    for(int T = 0; T < test_case; T++) {
        int N;
        cin >> N;

        pair<int, int> p[N];

        for(int i = 0; i < N; i++) {
            cin >> p[i].first >> p[i].second;
        }

        sort(p, p + N);

        int cnt = 1;
        int a, b;
        a = p[0].first;
        b = p[0].second;

        for(int i = 1; i < N; i++) {
            if(p[i].first > a && p[i].second < b) {
                cnt++;
                a = p[i].first;
                b = p[i].second;
            }
        }

        cout << cnt << endl;
        
    }
}