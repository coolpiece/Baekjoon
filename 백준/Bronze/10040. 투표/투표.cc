#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> pick(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) {
        int b;
        cin >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] <= b) {
                pick[i]++;
                break;
            }
        }
    }

    int mx = 0, game = 0;
    for (int i = 0; i < n; i++) {
        if (mx < pick[i]) {
            mx = pick[i];
            game = i;
        }
    }
    cout << game + 1;
}