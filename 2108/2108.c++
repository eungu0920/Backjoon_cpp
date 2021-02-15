#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    int many[8001];
    fill(many, many + 8002, 0);
    double ave = 0;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        many[arr[i] + 4000]++;
        ave += arr[i];
    }

    sort(arr, arr + N);

    int cnt = 0;

    for(int i = 0; i < 8002; i++) {
        cnt = cnt < many[i] ? many[i] : cnt;
    }

    int ret = 0;

    for(int i = 0; i < 8002; i++) {
        if(cnt == many[i]) {
            ret++;
        }
    }
    int temp[ret + 1];

    int j = 0;

    for(int i = 0; i < 8002; i++) {
        if(cnt == many[i]) {
            temp[++j] = i - 4000;
        }
    }

    printf("%.0f\n", ave / N);
    cout << arr[N/2] << endl;
    if(j > 1) {
        cout << temp[2] << endl;
    } else {
        cout << temp[1] << endl;
    }
    cout << arr[N - 1] - arr[0] << endl;
    

    return 0;
}