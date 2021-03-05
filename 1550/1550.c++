#include<iostream>
#include<string>

using namespace std;

int main() {
    string temp;
    cin >> temp;

    int k = 1;
    int result = 0;

    for(int i = temp.size() - 1; i >= 0; i--) {
        if(temp[i] >= '0' && temp[i] <= '9') {
            result += (temp[i] - '0') * k;
        } else {
            result += (temp[i] - 55) * k;
        }
        k *= 16;
    }

    cout << result << endl;

    return 0;
}