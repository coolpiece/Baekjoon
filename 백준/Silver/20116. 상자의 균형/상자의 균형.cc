#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, l, flag = 0;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    long double s = 0;  // 2~n번 상자들의 x좌표 합.
    for (int i = 1; i < n; i++) {
        s += v[n - i];
        long double avg = s / i;
        // cout << "L: " << v[n - i - 1] - l << ", R: " << v[n - i - 1] + l << ", AVG: " << avg << '\n';
        if (avg <= v[n - i - 1] - l || avg >= v[n - i - 1] + l) {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "unstable";
    else
        cout << "stable";
}