#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<int> input;
    vector<int> sum(n, 0);

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        input.push_back(b);
    }

    sort(input.begin(), input.end()); // 정렬
    
    for (int i = 0; i < n; i++) {
        if (i == 0)
            sum[0] = input[0];  // 누적합 계산
        else
            sum[i] = sum[i - 1] + input[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == 1) {
            cout << sum[r - 1] << '\n';
        } else {
            cout << sum[r - 1] - sum[l - 2] << '\n';
        }
    }
}