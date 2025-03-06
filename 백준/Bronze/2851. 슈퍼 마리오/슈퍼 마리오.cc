#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(10);
    int m1 = 100, m2 = 100;
    for(int i=0; i<10; i++) {
        cin >> v[i];
        if (i) v[i] += v[i - 1];
        if (v[i]<100) m1 = min(100 - v[i], m1); // 100보다 작은 경우.
        else
            m2 = min(v[i] - 100, m2); // 100보다 큰 경우.
    }
    if (m1 < m2) cout << 100 - m1;
    else
        cout << 100 + m2;
}