#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> input, v(n), d(n);  // input에 실제 입력값, v에 인덱스, d에 이동 거리 저장.
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
        v[a - 1] = i; // 해당 값이 들어있는 인덱스 저장.
    }

    for (int i = 0; i < n - 1; i++) {
        if (v[i] == i) continue;
        int idx = v[i]; // 최솟값의 현재 인덱스 저장.

        int dis = idx - i;
        d[i] += dis;
        d[input[i] - 1] += dis;
        swap(v[i], v[input[i] - 1]);
        swap(input[i], input[idx]);
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
}