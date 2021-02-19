#include<iostream>
#define ll long long int

using namespace std;

// 거리와 가격이 최대 1,000,000,000이하로
// 들어옴으로 int로는 계산이 불가능 하다.
ll total = 0;
ll mini = 1000000001;

int main() {
    int N;
    cin >> N;

    ll distance[N];
    ll price[N];

    for(int i = 0; i < N-1; i++) {
        cin >> distance[i];
    }

    for(int i = 0; i < N-1; i++) {
        // 마지막 주유소의 값은 계산에 포함 될 일이 없으므로 생략
        cin >> price[i];
        mini = mini > price[i] ? price[i] : mini;
        // minimun값과 비교해서 가격이 더 낮을 때 가격 교체
        total += mini * distance[i];
        // minimum값과 거리값을 곱해서 총합에 덧셈.
    }

/* 처음에 짰던 코드
    int start = 0;
    int end = 1;

    while(end != N) {
        if(price[start] <= price[end]) {
            total += distance[end] * price[start];
        } else {
            total += distance[end] * price[start];
            start = end;
        }
        end++;
    }
*/

    cout << total << "\n";

    return 0;
}