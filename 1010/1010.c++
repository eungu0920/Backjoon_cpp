#include<iostream>

using namespace std;

int main() {
    int C[31][31];
    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;

    fill(C[0], C[31], 1);

    for(int i = 2; i < 31; i++) {
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    int testCase;

    cin >> testCase;

    for(int i = 0; i < testCase; i++) {
        int N, M;

        cin >> N >> M;

        cout << C[M][N] << endl;
    }

    return 0;
}