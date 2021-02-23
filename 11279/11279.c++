#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

void push(int data) {
    int i = v.size();
    v.push_back(data);

    while(i != 0 && v[i] > v[(i-1)/2]) {
        swap(v[i], v[(i-1)/2]);
        i = (i-1)/2;
    }
}

int pop() {
    if(v.size() == 0) {
        return 0;
    }

    int val = v[0];
    v[0] = v[v.size()-1];
    v.pop_back();
    int p = 0;

    while(1) {
        int child = p*2 + 1;

        if(child >= v.size()) {
            break;
        }

        if(v[child] < v[child+1]) {
            child++;
        }

        if(v[child] > v[p]) {
            swap(v[child], v[p]);
            p = child;
        }
        else break;
    }
    return val;
}

int main() {
    int test;

    cin >> test;

    for(int i = 0; i < test; i++) {
        int input;
        cin >> input;

        if(input == 0) {
            cout << pop() << endl;
        } else {
            push(input);
        }
    }

    return 0;
}