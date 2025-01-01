#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, output = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) { // 각 줄 읽기.
        vector<int> input(n);
        for (int j = 0; j <= i; j++) { // 입력 받으면서 최댓값 계산.
            cin >> input[j];
            if(j==0)
                input[j] += v[j];
            else if(j==i)
                input[j] = v[j - 1] + input[j];
            else input[j] = max(v[j] + input[j], v[j - 1] + input[j]);
        }
        v = input;
    }

    for (int j = 0; j < n; j++) output = max(output, v[j]);
    cout << output;
}