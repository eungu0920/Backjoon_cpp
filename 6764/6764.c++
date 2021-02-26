#include<iostream>

int main() {
    int arr[4];
    int result = 0;

    for(int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
        if(i > 0) {
            if(arr[i-1] < arr[i]) {
                result += 1;
            } else if(arr[i-1] > arr[i]) {
                result += 10;
            } else {
                result += 0;
            }
        }
    }

    if(result == 0) {
        printf("Fish At Constant Depth\n");
    } else if(result == 3) {
        printf("Fish Rising\n");
    } else if(result == 30) {
        printf("Fish Diving\n");
    } else {
        printf("No Fish\n");
    }

    return 0;
}