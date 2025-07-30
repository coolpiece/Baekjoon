#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, point = 0;
    cin >> n >> a >> b;
    vector<vector<int>> x(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> x[i][j];

    for (int i = 0; i < n; i++) point = max(point, x[a-1][i]);
    for (int i = 0; i < n; i++) point = max(point, x[i][b-1]);
    if (point > x[a-1][b-1]) cout << "ANGRY";
    else
        cout << "HAPPY";
}