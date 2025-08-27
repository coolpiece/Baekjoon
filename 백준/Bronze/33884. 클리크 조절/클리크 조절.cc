#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    multiset<pair<int, int>> s1, s2; // multimap은 value 정렬 X -> multiset 사용.
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        s1.insert({x, y});
    }

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        s2.insert({x, y});
    }

    cout << s2.begin()->first - s1.begin()->first << " " << s2.begin()->second - s1.begin()->second;
}