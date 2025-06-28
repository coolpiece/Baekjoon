#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    reverse(v.begin(), v.end());
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[idx]) {
            for (int j = idx; j < i; j++) v[j] = v[idx];
            idx = i;
        }
        else if(i==n-1)
            for (int j = idx; j <= i; j++) v[j] = v[idx];
        
    }

    long long s = 0;
    for (int i = 0; i < n; i++) s += v[i];
    cout << s;
    return 0;
}