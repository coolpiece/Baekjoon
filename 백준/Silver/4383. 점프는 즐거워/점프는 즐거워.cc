#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        int flag = 1;
        vector<int> v(n), rst(n - 1);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n - 1; i++) {
            rst[i] = v[i] - v[i + 1];
            if (rst[i] < 0) rst[i] *= (-1);
        }
        sort(rst.begin(), rst.end());
        for (int i = 0; i < n - 1; i++) {
            if (rst[i] != i + 1) {
                flag = 0;
                break;
            }
        }

        if (!flag)
            cout << "Not jolly\n";
        else
            cout << "Jolly\n";
    }
}