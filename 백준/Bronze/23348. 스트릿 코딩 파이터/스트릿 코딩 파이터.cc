#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < 3; j++) {
            int pa, pb, pc;
            cin >> pa >> pb >> pc;
            s += pa * a + pb * b + pc * c;
        }
        v[i] = s;
    }
    sort(v.begin(), v.end(), greater<>());
    cout << v[0];
}