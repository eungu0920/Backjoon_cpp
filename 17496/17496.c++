#include<iostream>

int main() {
    int N, T, C, P;
    int total = 0;

    scanf("%d %d %d %d", &N, &T, &C, &P);
    
    N -= T;

    while(N > 0) {
        N -= T;
        total += C * P;
    }

    printf("%d\n", total);

    return 0;
}