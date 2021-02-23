#include<iostream>

using namespace std;

int youngest, middle, oldest;

int main() {
    cin >> youngest >> middle;
    oldest = middle + (middle - youngest);
    cout << oldest << "\n";
    return 0;
}