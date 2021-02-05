#include<iostream>

using namespace std;

int main() {
    int arr[7];
    int odd[7];
    int cnt = 0;
    int total = 0;

    for(int i = 0; i < 7; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 1) {
            odd[cnt++] = arr[i];
            total += arr[i];
        }
    }

    int min = 100;

    for(int i = 0; i < cnt; i++) {
        if(odd[i] < min) {
            min = odd[i];
        }
    }

    if(cnt == 0) {
        printf("-1");
    } else {
        printf("%d\n%d", total, min);
    }

    return 0;
}