#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        if (n > 32) {
            cout << 0 << '\n';
        }
        else {
            vector<int> d;
            int rst = 8;
            for (int j = 0; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {
                        int dis = 0;
                        for (int m = 0; m < 4; m++) {
                            if (v[j][m] != v[k][m]) dis++;
                            if (v[j][m] != v[l][m]) dis++;
                            if (v[k][m] != v[l][m]) dis++;                        
                        }
                        if (rst > dis) rst = dis;
                    }
                }
            }

            cout << rst << '\n';
        }
    }
}