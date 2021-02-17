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
    // 이분탐색을 수행하기위해 정렬을 수행

    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        int temp;
        int left = 0;
        int right = N - 1;
        int result = 0;

        scanf("%d", &temp);

        while(left <= right) {
            // 이분 탐색
            int mid = (left + right) / 2;

            if(temp == arr[mid]) {
                // 중복값이 없으므로 일치하면 바로 결과에 1을 넣고 while문 탈출
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