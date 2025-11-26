#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int na, nb;
    cin >> na >> nb;
    set<int> a;
    for (int i = 0; i < na; i++) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < nb; i++) {
        int tmp;
        cin >> tmp;
        if (a.find(tmp) != a.end()) a.erase(tmp);
    }

    if (a.empty()) cout << 0;
    else {
        cout << a.size() << '\n';
        for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    }
}