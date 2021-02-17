#include<iostream>
#include<string>

using namespace std;

long long int result = 0;
long long int x = 1;

int main() {
    int L;
    string s;

    cin >> L >> s;

    for(int i = 0; i < L; i++) {
        result += ((s[i] - 96) * x) % 1234567891;

        x = (x * 31) % 1234567891;
    }

    cout << result << endl;

    return 0;
}