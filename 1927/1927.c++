#include<iostream>
#include<vector>

using namespace std;

/*
왼쪽 자식 노드 = 부모 노드 * 2 + 1
오른쪽 자식 노드 = 부모 노드 * 2 + 2
부모 노드 = 현재 노드 - 1 / 2
*/

vector<int> heap;

void push(int data) {
    int i = heap.size();
    heap.push_back(data);

    while(i != 0 && heap[i] < heap[(i-1)/2]) {
        // 첫번째 값이 아니면서 들어온 값이 자신의 부모노드보다 클 때
        swap(heap[i], heap[(i-1)/2]);
        // 부모와 자식 교체 후
        i = (i-1)/2;
        // 부모 노드로 올라가서 비교
    }
}

int pop() {
    if(heap.size() == 0) {
        return 0;
    }

    int result = heap[0];
    // 최소 힙의 맨 첫번째 값을 변수에 입력 후
    heap[0] = heap[heap.size() - 1];
    // 힙의 맨 마지막 값을 첫번째 값으로 올린 후
    heap.pop_back();
    // 마지막 노드 삭제

    int p = 0;

    // 첫번째 노드의 값을 아래로 내려가며 비교 후 교체
    while(1) {
        int child = p*2 + 1;
        // 왼쪽 자식노드

        if(child >= heap.size()) {
            // 자식노드가 더이상 없을 때
            break;
        }

        if(heap[child] > heap[child + 1]) {
            // 왼쪽 자식노드가 오른쪽 자식노드보다 클 때
            child++;
        }

        if(heap[child] < heap[p]) {
            // 자식노드 보다 부모노드가 크면
            swap(heap[child], heap[p]);
            // 서로 교체 후
            p = child;
            // 아래로 내려간다
        } else {
            // 부모노드가 더 작으면
            break;
        }
    }
    return result;
}

int main() {
    int test;

    scanf("%d", &test);

    for(int i = 0; i < test; i++) {
        int input;
        scanf("%d", &input);

        if(input == 0) {
            printf("%d\n", pop());
        } else {
            push(input);
        }
    }

    return 0;
}