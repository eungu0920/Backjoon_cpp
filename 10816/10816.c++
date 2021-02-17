#include<iostream>
#include<algorithm>

using namespace std;

int arr[500000];

int main() {
    int N, M;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);

        printf("%d ", upper_bound(arr, arr + N, temp) - lower_bound(arr, arr + N, temp));
   }    

    return 0;
}