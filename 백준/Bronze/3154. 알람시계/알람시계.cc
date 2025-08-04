#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    vector<pair<int, int>> v = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

    int min = 99, hrst, mrst;
    int h = (str[0] - '0') * 10 + (str[1] - '0'), m = (str[3] - '0') * 10 + (str[4] - '0');
    for (int i = h; i < 100; i += 24) {
        int e1 = abs(v[i / 10].first - v[i % 10].first) + abs(v[i / 10].second - v[i % 10].second), e2 = abs(v[i % 10].first - v[m / 10].first) + abs(v[i % 10].second - v[m / 10].second),
            e3 = abs(v[m / 10].first - v[m % 10].first) + abs(v[m / 10].second - v[m % 10].second);
        if (min > e1 + e2 + e3) {
            min = e1 + e2 + e3;
            hrst = i;
            mrst = m;
        }

        if (m / 10 <= 3) {
            e2 = abs(v[i % 10].first - v[m / 10 + 6].first) + abs(v[i % 10].second - v[m / 10 + 6].second),
            e3 = abs(v[m / 10 + 6].first - v[m % 10].first) + abs(v[m / 10 + 6].second - v[m % 10].second);
            if (min > e1 + e2 + e3) {
                min = e1 + e2 + e3;
                hrst = i;
                mrst = m + 60;
            }
        }
    }

    if (hrst < 10) cout << '0';
    cout << hrst << ':';

    if (mrst < 10) cout << '0';
    cout << mrst;
}