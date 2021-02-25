#include<iostream>

using namespace std;

int main() {
    int antenna, eyes;

    cin >> antenna >> eyes;

    if(antenna >= 3 && eyes <= 4) {
        cout << "TroyMartian\n"; 
    }

    if(antenna <= 6 && eyes >= 2) {
        cout << "VladSaturnian\n";
    }

    if(antenna <= 2 && eyes <= 3) {
        cout << "GraemeMercurian\n";
    }

    return 0;

}