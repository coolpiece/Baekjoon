#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (v[0] % 2 == 0 && v[1] % 2 == 0 && v[2] % 2 == 0) cout << v[0] * v[1] * v[2];
    else {
        int rst = 1;
        for (int i = 0; i < 3; i++){
            if (v[i] % 2) rst *= v[i];
        }
        cout << rst;
    }
}