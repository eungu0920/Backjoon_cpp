#include<iostream>

using namespace std;

int main() {
    int total = 0;

    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        total += x;
    }

    cout << total << "\n";

    return 0;
}