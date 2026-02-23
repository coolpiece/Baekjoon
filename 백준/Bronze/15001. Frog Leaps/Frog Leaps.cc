#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    long long sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        long long dis = v[i] - v[i - 1];
        sum += dis * dis;
    }
    cout << sum;
}