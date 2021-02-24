#include<iostream>

using namespace std;

int main() {
    int D, H, M;
    
    cin >> D >> H >> M; // date, hours, minutes

    D -= 11;
    H -= 11;
    M -= 11;

    if(M < 0) {
        H--;
        M += 60;
    }

    if(H < 0) {
        D--;
        H += 24;
    }

    if(D < 0) {
        // D가 음수면 끝나는 시간이 시작시간보다 빠름
        cout << -1 << "\n";
    } else {
        // 하루는 1440분이므로 D*1440
        cout << D*1440 + H*60 + M << "\n";
    }

    return 0;
}