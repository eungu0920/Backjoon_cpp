#include<iostream>
#include<vector>

using namespace std;

vector<int> heap;

/*
왼쪽 자식의 인덱스 = 부모 인덱스 * 2 + 1
오른쪽 자식의 인덱스 = 부모 인덱스 * 2 + 2
부모 인덱스 = (자신 인덱스 - 1) / 2
*/

void push(int data) {
    int i = heap.size();
    heap.push_back(data);

    while(i != 0 && abs(heap[i]) <= abs(heap[(i-1)/2])) {
        // 절댓값이 같거나 부모노드의 절댓값이 더 클 때
        if(abs(heap[i]) == abs(heap[(i-1)/2])) {
            // 절댓값이 같을 때
            if(heap[i] < heap[(i-1)/2]) {
               // 부모노드의 값이 클 때 (들어온 값이 음수이면서 부모노드의 값이 양수일 때)
                swap(heap[i], heap[(i-1)/2]);
            }
            i = (i-1) / 2;
            continue;
            // 중복된 값이 있을 수 있으므로 계속 비교해가며 바꿔줘야하므로 continue사용
        }

        swap(heap[i], heap[(i-1)/2]);
        // 절댓값이 같지 않은경우 swap만 실행
        i = (i-1) / 2;
        // 부모노드쪽으로 올라가면서 계속 비교
    }
}

int pop() {
    if(heap.size() == 0) {
        return 0;
    }

    int result = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    int p = 0;

    while(true) {
        int child = p * 2 + 1;

        if(child >= heap.size()) {
            // 자식이 더이상 없을 때
            break;
        }

        if(abs(heap[child]) > abs(heap[child + 1])) {
            // 왼쪽 자식의 절댓값이 오른쪽 자식의 절댓값보다 큰 경우
            child++;
            // 오른쪽 자식으로 넘어감
        } else if(abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1]) {
            // 절댓값이 같으면서 왼쪽 자식의 값이 큰 경우
            child++;
            // 오른쪽 자식의 값이 음수이니 오른쪽 자식으로 넘어감
        }

        if(abs(heap[child]) < abs(heap[p])) {
            // 부모 노드가 자식 노드보다 더 큰경우
            swap(heap[child], heap[p]);
            // 작은 값이 올라가야 하므로 swap실행
            p = child;
            // 아래로 내려가서 비교
        } else if(abs(heap[child]) == abs(heap[p]) && heap[child] < heap[p]) {
            // 절댓값이 같으면서 부모 노드의 값이 양수 일 때
            swap(heap[child], heap[p]);
            p = child;
        } else {
            // 자식노드가 더 큰 값을 가지고 있는 경우
            break;
        }

    }

    return result;

}

int main() {
    int test_case;
    scanf("%d", &test_case);

    for(int t = 0; t < test_case; t++) {
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