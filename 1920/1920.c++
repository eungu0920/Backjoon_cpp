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

    scanf("%d", &M);

    int search[M];

    for(int i = 0; i < M; i++) {
        scanf("%d", &search[i]);
    }

    sort(arr, arr + N);
    // 이분탐색을 실행하기 위해 정렬을 수행함

    for(int i = 0; i < M; i++) {
        int target = search[i]; // 탐색할 수를 꺼냄

        int left = 0; // 배열의 첫 번째부터
        int right = N - 1; // 배열의 마지막까지
        
        while(true) {
            int mid = (left + right) / 2;
        
            if(target == arr[mid]) {
                // 탐색하려는 수가 배열에 있는 수와 같다면
                search[i] = 1;
                break;
                // 배열에 1을 넣고 다음으로 넘어감
            } else if(target > arr[mid]) {
                // 탐색하려는 수가 배열에 있는 수 보다 크다면
                left = mid + 1;
                // 중간 값을 기준으로 오른쪽으로 탐색을 시작함
            } else {
                // (target < arr[mid]) 탐색하려는 수가 배열에 있는 수 보다 작다면
                right = mid - 1;
                // 중간 값을 기준으로 왼쪽으로 탐색을 시작함
            }

            if(left > right) {
                // 배열에 있는 수를 찾지 못하였을 때
                search[i] = 0;
                break;
                // 0을 넣고 다음으로 넘어감
            }
        }
    }

    for(int i = 0; i < M; i++) {
        printf("%d\n", search[i]);
    }

    return 0;
}