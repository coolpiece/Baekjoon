#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> v(100001);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[tmp]++;
        for (int j = tmp; j <= k; j++) {
            v[j] = v[j] + v[j - tmp];
        }
    }

    cout << v[k];
}