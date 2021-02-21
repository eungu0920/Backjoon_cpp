#include<iostream>

using namespace std;

int chess[6] = {1, 1, 2, 2, 2, 8};

int main() {
    int white[6];

    for(int i = 0; i < 6; i++) {
        cin >> white[i];
        chess[i] -= white[i];
    }

    for(int i = 0; i < 6; i++) {
        cout << chess[i] << " ";
    }
    
    return 0;
}