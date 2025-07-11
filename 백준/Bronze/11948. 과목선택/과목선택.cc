#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(4);
    int e, f;
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> e >> f;
    sort(v.begin(), v.end(), greater<>());
    cout << v[0] + v[1] + v[2] + max(e, f);
}