#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v(501, vector<int>(501));

    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                if (!v[j][k]) cnt++;
                v[j][k] = 1;
            }
        }
    }
    cout << cnt;
}