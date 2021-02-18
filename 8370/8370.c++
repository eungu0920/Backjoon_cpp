#include<iostream>

using namespace std;

int main() {
    int bR, eR, B, E;
    // bR : rows of seats in the business class.
    // eR : rows of seats in the economic class.
    // B : business seats.
    // E : economic seats.

    cin >> bR >> B >> eR >> E;

    cout << (bR * B) + (eR * E) << "\n";

    return 0;
}