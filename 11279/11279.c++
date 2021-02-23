#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

/*
왼쪽 자식의 인덱스 = 부모 인덱스 * 2 + 1
오른쪽 자식의 인덱스 = 부모 인덱스 * 2 + 2
부모 인덱스 = 자신 인덱스 - 1 / 2
*/

void push(int data) {
    int i = v.size();
    v.push_back(data);

    while(i != 0 && v[i] > v[(i-1)/2]) {
        // 처음 삽입할 때가 아니면서 부모노드보다 자식노드가 클 때
        swap(v[i], v[(i-1)/2]);
        // 부모노드와 자식노드 위치 교환 후
        i = (i-1)/2;
        // 부모노드로 올라가서 다시 비교 후 교체
    }
}

int pop() {
    if(v.size() == 0) {
        return 0;
    }

    int result = v[0];
    // 최대 힙의 맨 첫번째 값을 변수에 입력 후
    v[0] = v[v.size()-1];
    // 힙의 맨 마지막 값을 첫번째 값으로 올림
    v.pop_back();
    // 마지막 노드 삭제
    int p = 0;

    // 첫번째 노드의 값을 아래로 내려가며 비교후 교체
    while(1) {
        int child = p * 2 + 1;
        // 왼쪽 자식의 값

        if(child >= v.size()) {
            // 자식이 더이상 없을 때
            break;
        }

        if(v[child] < v[child+1]) {
            // 왼쪽 자식보다 오른쪽 자식이 더 클 때
            child++;
        }

        if(v[child] > v[p]) {
            // 자식노드 더 크다면
            swap(v[child], v[p]);
            // 부모노드와 교체 한 후
            p = child;
            // 아래로 내려간다.
        } else {
            // 부모노드가 자식노드보다 크면
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