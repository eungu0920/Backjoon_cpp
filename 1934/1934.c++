#include<iostream>

using namespace std;

int gcd(int A, int B) {
    int temp = 0;

    while(B > 0) {
        temp = B;
        B = A % B;
        A = temp;    
    }

    return A;
}

int lcm(int A, int B) {
    return (A * B) / gcd(A, B);
}

int main() {
    int testCase;

    cin >> testCase;

    for(int T = 0; T < testCase; T++) {
        int A, B;

        cin >> A >> B;

        cout << lcm(A, B) << endl;
    }

}