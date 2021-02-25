#include<iostream>

using namespace std;

int main() {
    int limit, nowSpeed;
    cin >> limit >> nowSpeed;

    nowSpeed -= limit;

    if(nowSpeed <= 0) {
        cout << "Congratulations, you are within the speed limit!\n";
    } else if(nowSpeed <= 20) {
        cout << "You are speeding and your fine is $100.\n";
    } else if(nowSpeed <= 30) {
        cout << "You are speeding and your fine is $270.\n";
    } else {
        cout << "You are speeding and your fine is $500.\n";
    }

    return 0;
}