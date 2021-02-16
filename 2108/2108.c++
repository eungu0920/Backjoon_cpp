#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    int many[8001]; // 최빈값을 찾아내기 위한 배열
    fill(many, many + 8002, 0); // 모든 배열 0으로 초기화
    double ave = 0;

    for(int i = 0; i < N; i++) {
        // 값을 입력과 동시에 최빈값 계산 및 평균값 계산을 한다.
        cin >> arr[i];
        many[arr[i] + 4000]++;
        // 값에는 음수 값도 포함되어 있으므로 4000을 더한 값으로 계산한다.
        ave += arr[i];
    }

    sort(arr, arr + N);
    // 오름차순으로 정렬

    int cnt = 0;
    // 최빈값을 계산하기 위한 변수

    for(int i = 0; i < 8002; i++) {
        cnt = cnt < many[i] ? many[i] : cnt;
    }
    // 가장 많이 입력된 수의 개수가 변수에 입력된다.

    int ret = 0;
    // 최빈값이 중복되는 경우를 위한 변수

    for(int i = 0; i < 8002; i++) {
        if(cnt == many[i]) {
            // 최빈값이 중복 되는 경우 그 수를 카운트한다.
            ret++;
        }
    }

    int temp[ret + 1];
    // 중복되는 최빈값의 개수만큼 배열을 생성한다.

    int j = 0;

    for(int i = 0; i < 8002; i++) {
        if(cnt == many[i]) {
            temp[++j] = i - 4000;
            // 최빈값을 배열의 0부터가 아닌 1부터 채운다.
        }
    }

    printf("%.0f\n", ave / N);
    cout << arr[N/2] << endl;
    if(j > 1) {
        // 최빈값이 2개 이상인 경우
        cout << temp[2] << endl;
    } else {
        // 최빈값이 1개인 경우
        cout << temp[1] << endl;
    }
    cout << arr[N - 1] - arr[0] << endl;
    

    return 0;
}