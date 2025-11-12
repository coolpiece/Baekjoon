#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, len = 0;
    cin >> n;
    vector<int> rst(101);
    vector<int> idx(101);
    idx[0] = -1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = 1;
            if (a[i] == b[j]) {
                while (b[j] <= rst[k] && k <= len) k++;
                if (idx[k - 1] < j) {
                    idx[k] = j;
                    rst[k] = b[j];
                    len = k;
                    break;
                }
            }
        }
    }
    cout << len << '\n';
    for (int i = 1; i <= len; i++) cout << rst[i] << ' ';
}