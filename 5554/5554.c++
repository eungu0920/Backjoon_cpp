#include<iostream>

int main() {
    int total = 0;
    for(int i = 0; i < 4; i++) {
        int temp;
        scanf("%d", &temp);

        total += temp;
    }

    printf("%d\n", total / 60);
    printf("%d\n", total % 60);

    return 0;
}