#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, min, front, back, left, right;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    front = 0;
    back = v.size() - 1;
    min = abs(v[front] + v[back]);
    while(front < back) {
        int temp = v[front] + v[back];
        if(temp == 0) {
            left = v[front];
            right = v[back];
            break;
        }
        if(abs(temp) <= min) {
            min = abs(temp);
            left = v[front];
            right = v[back];
        }
        if (temp < 0) {
            front++;
        }
        else if (temp > 0) {
            back--;
        }
    }

    cout << left << " " << right;
}