#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    multimap<int, int> m;  // <결승선으로부터의 거리, 카약 번호>
    vector<int> v(10);     // 등수.

    for (int i = 0; i < r; i++) {
        string str;
        cin >> str;
        for (int j = 1; j < c - 1; j++) {
            if (str[j] != 'S' && str[j] != '.' && str[j] != 'F') {
                m.insert({c - 4 - j, str[j] - '0'});
                break;
            }
        }
    }

    int rank = 1, dis = m.begin()->first;
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->first == dis)
            v[i->second] = rank;
        else {
            v[i->second] = ++rank;
            dis = i->first;
        }
    }

    for (int i = 1; i <= 9; i++) cout << v[i] << '\n';
}