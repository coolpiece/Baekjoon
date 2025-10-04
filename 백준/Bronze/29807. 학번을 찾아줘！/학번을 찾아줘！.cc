#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long n = 0;
    vector<int> v(5);
    cin >> t;
    for (int i = 0; i < t; i++) cin >> v[i];

    if (v[0] > v[2])
        n += abs(v[0] - v[2]) * 508;
    else
        n += abs(v[0] - v[2]) * 108;

    if (v[1] > v[3])
        n += abs(v[1] - v[3]) * 212;
    else
        n += abs(v[1] - v[3]) * 305;

    if (v[4]) n += v[4] * 707;
    cout << n * 4763;
}