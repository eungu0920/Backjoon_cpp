#include<iostream>

using namespace std;

int main() {
    int arr[5];
    int total = 0;

    cin >> arr[0];
    total = arr[0];

    for(int i = 1; i < 3; i++) {
        cin >> arr[i];
        if(arr[i] < total)
            total = arr[i];
    }

    for(int i = 3; i < 5; i++) {
        cin >> arr[i];
    }

    total += arr[3] > arr[4] ? arr[4] : arr[3];

    cout << total - 50 << endl;

    return 0;
}