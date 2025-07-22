#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x = 500, y = 500;
    cin >> n >> k;
    vector<vector<int>> v(1001, vector<int>(1001));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a + 500][b + 500] = 1;
    }
    string str;
    cin >> str;
    for (int i = 0; i < k; i++) {
        switch (str[i]) {
            case 'U':
                if (!v[x][y + 1]) y++;
                break;
            case 'D':
                if (!v[x][y - 1]) y--;
                break;
            case 'R':
                if (!v[x + 1][y]) x++;
                break;
            case 'L':
                if (!v[x - 1][y]) x--;
                break;
            default:
                break;
        }
    }
    cout << x - 500 << " " << y - 500;
}