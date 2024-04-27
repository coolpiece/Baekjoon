#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cur = 0, count = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (v[i]!=cur) continue;
        if (cur == 2) cur = 0;
        else cur++;
        count++;
    }
    cout << count;
}