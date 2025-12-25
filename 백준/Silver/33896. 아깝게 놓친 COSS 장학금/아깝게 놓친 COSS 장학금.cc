#include <bits/stdc++.h>
using namespace std;

struct student {
    string name;
    int score, risk, cost, coss;
};

bool compare(student s1, student s2) {
    if (s1.coss == s2.coss) {
        if (s1.cost == s2.cost) {
            return s1.name < s2.name;
        }
        return s1.cost < s2.cost;
    }
    return s1.coss > s2.coss;
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<student> v;
    for (int i = 0; i < n; i++) {
        student s;
        cin >> s.name >> s.score >> s.risk >> s.cost;
        s.coss = (s.score * s.score * s.score) / (s.cost * (s.risk + 1));
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);
    cout << v[1].name;
}