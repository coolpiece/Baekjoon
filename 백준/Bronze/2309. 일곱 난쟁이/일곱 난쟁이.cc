#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> v;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        int n;
        cin >> n;
        v.push_back(n);
        sum += n;
    }
    int over = sum - 100;
    sort(v.begin(), v.end());

    for (int i = 0; i < 8; i++) {
        int flag = 0;
        for (int j = i + 1; j < 9; j++) {
            if (v[i] + v[j] == over) {
                v[i] = 0;
                v[j] = 0;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }

    for (int i = 0; i < 9; i++) {
        if (v[i] == 0) continue;
        cout << v[i] << '\n';
    }
}