#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    int arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for(int i = 0; i < M; i++) {
        int temp;
        cin >> temp;

        cout << upper_bound(arr, arr + N, temp) << "\n";
    }


    return 0;
}