#include<iostream>

using namespace std;

int main() {
    int L, P;
    
    cin >> L >> P;

    int area = L * P;

    for(int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        
        cout << temp - area << " ";
    }

    return 0;
}