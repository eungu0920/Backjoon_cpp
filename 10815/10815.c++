#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N, M;

    scanf("%d", &N);

    int arr[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        int temp;
        int left = 0;
        int right = N - 1;
        int result = 0;

        cin >> temp;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(temp == arr[mid]) {
                result = 1;
                break;
            } else if(temp > arr[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        printf("%d ", result);
    }

    return 0;
}