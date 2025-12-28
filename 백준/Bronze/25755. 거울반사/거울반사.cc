#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    char w;
    int n;
    cin >> w >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    if (w == 'L' || w == 'R') {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (v[i][j] == 1 || v[i][j] == 8)
                    cout << v[i][j] << ' ';
                else if (v[i][j] == 2)
                    cout << 5 << ' ';
                else if (v[i][j] == 5)
                    cout << 2 << ' ';
                else
                    cout << "? ";
            }
            cout << '\n';
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 1 || v[i][j] == 8)
                    cout << v[i][j] << ' ';
                else if (v[i][j] == 2)
                    cout << 5 << ' ';
                else if (v[i][j] == 5)
                    cout << 2 << ' ';
                else
                    cout << "? ";
            }
            cout << '\n';
        }
    }
}