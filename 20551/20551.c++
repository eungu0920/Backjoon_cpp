#include<iostream>
#include<algorithm>

using namespace std;

int grayLower_bound(int* arr, int N, int temp) {
    int left = 0;
    int right = N;
    int cnt = 0;
    // 탐색하려는 수가 없을 때 -1을 리턴하기 위해 카운트 변수 선언
    int mid;

    while(left < right) {
        mid = (left + right) / 2;

        if(arr[mid] < temp) {
            left = mid + 1;
        } else {
            right = mid;
        }

        if(arr[mid] == temp) {
            // 배열에 탐색하려는 수가 있을 때 카운트 증가
            cnt++;
        }
    }

    if(cnt != 0) {
        return right;
    } else {
        return -1;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    for(int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);

        printf("%d\n", grayLower_bound(arr, N, temp));
    }
    return 0;
}