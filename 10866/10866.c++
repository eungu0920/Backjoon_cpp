#include<string>
#include<iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Deque{
    int count;
    Node *front;
    Node *rear;
};

void push_front(Deque *deque, int data) {
    Node *node = new Node();
    node->data = data;
    if(deque->front == NULL) {
        // 데이터를 처음 넣을 때
        deque->front = node;
        deque->rear = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        // 데이터가 한개 이상인 경우
        deque->front->next = node;
        // front의 다음 노드에 복사
        node->prev = deque->front;
        // 새로운 노드의 이전 연결을 front에 함
        node->next = NULL;
        // 새로운 노드의 다음은 NULL값
        deque->front = node;
    }
    deque->count++;
}

void push_back(Deque *deque, int data) {
    Node *node = new Node();
    node->data = data;
    if(deque->rear == NULL) {
        // 데이터를 처음 넣을 때
        deque->front = node;
        deque->rear = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        deque->rear->prev = node;
        // 뒤에 연결하므로 rear의 prev에 node를 연결
        node->prev = NULL;
        node->next = deque->rear;
        deque->rear = node;
    }
    deque->count++;
}

int pop_front(Deque *deque) {
    Node *node = deque->front;
    int data = node->data;
    if(deque->front->prev == NULL) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->prev;
        deque->front->next = NULL;
    }
    free(node);
    deque->count--;
    return data;
}

int pop_back(Deque *deque) {
    Node *node = deque->rear;
    int data = node->data;
    if(deque->rear->next == NULL) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->next;
        deque->rear->prev = NULL;
    }
    free(node);
    deque->count--;
    return data;
}

int front(Deque *deque) {
    int data = deque->front->data;
    return data;
}

int back(Deque *deque) {
    int data = deque->rear->data;
    return data;
}

int main() {
    Deque deque;
    deque.front = deque.rear = NULL;
    deque.count = 0;

    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if(s == "push_front") {
            int data;
            scanf("%d", &data);
            push_front(&deque, data);
        } else if(s == "push_back") {
            int data;
            scanf("%d", &data);
            push_back(&deque, data);
        } else if(s == "pop_front") {
            if(deque.count == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pop_front(&deque));
            }
        } else if(s == "pop_back") {
            if(deque.count == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pop_back(&deque));
            }
        } else if(s == "size") {
            printf("%d\n", deque.count);
        } else if(s == "empty") {
            if(deque.count == 0) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if(s == "front") {
            if(deque.count == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", deque.front->data);
            }
        } else if(s == "back") {
            if(deque.count == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", deque.rear->data);
            }
        }

    }

    return 0;
    
}