#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 1;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        v.push_back(h);
    }
    for (int i = 1; i < n; i++) {
        if (v[i - 1] <= v[i]) count++;
    }
    cout << count;
}