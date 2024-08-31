#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v(5);  // 점수, 번호
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        v[i] = {sum, i + 1};
    }
    sort(v.begin(), v.end(), greater<>());
    cout << v[0].second << " " << v[0].first;
}