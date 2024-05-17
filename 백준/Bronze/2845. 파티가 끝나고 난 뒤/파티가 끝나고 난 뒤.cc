#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, p;
    cin >> l >> p;
    p *= l; // 참가자의 수

    vector<int> v(5);
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
    cout << v[0] - p << " " << v[1] - p << " " << v[2] - p << " " << v[3] - p << " " << v[4] - p;
}