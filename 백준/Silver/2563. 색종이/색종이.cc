#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<char>> v(101, vector<char>(101));
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) v[a + j][b + k] = 1;
        }
    }

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            if (v[i][j] == 1) cnt++;
    cout << cnt;
}