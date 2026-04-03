#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k, a;
    cin >> n >> k >> a;
    k /= a;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        int cycle = k / t;
        time[i] += cycle * (t + s);
        int remain = k - cycle * t;
        if (remain == 0)
            time[i] -= s;
        else
            time[i] += remain;
    }
    sort(time.begin(), time.end());
    cout << time[0];
}