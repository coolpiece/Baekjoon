#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v(3);
    int idx = -1;  // 3의 배수 인덱스 저장.
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
        if (!v[i].compare("Fizz"))
            idx = i;
        else if (idx == -1 && !v[i].compare("FizzBuzz"))
            idx = i;
    }

    int n;
    string str;
    if (idx == 0) {
        if (!v[1].compare("Buzz")) {  // 3의 배수, 5의 배수, ?, 3의 배수
            n = stoi(v[2]) + 1;
            if (n % 5)
                cout << "Fizz";
            else
                cout << "FizzBuzz";
        } else {  // 3의 배수, ?, ?, 3의 배수
            n = stoi(v[1]) + 2;
            if (n % 5)
                cout << "Fizz";
            else
                cout << "FizzBuzz";
        }
    } else if (idx == 1) {
        if (!v[0].compare("Buzz")) {  // 5의 배수, 3의 배수, ?, ?
            n = stoi(v[2]) + 1;
            cout << n;
        } else {  // ?, 3의 배수, ?, ?
            n = stoi(v[0]) + 3;
            if (n % 5)
                cout << n;
            else
                cout << "Buzz";
        }
    } else {
        if (!v[0].compare("Buzz")) {  // 5의 배수, ?, 3의 배수, ?
            n = stoi(v[1]) + 2;
            cout << n;
        } else {  // ?, ?, 3의 배수, ?
            n = stoi(v[0]) + 3;
            if (n % 5)
                cout << n;
            else
                cout << "Buzz";
        }
    }
}