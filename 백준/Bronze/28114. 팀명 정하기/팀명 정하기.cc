#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> p, y;
    vector<string> s;

    for (int i = 0; i < 3; i++) {
        int p1, y1;
        string s1;
        cin >> p1 >> y1 >> s1;

        p.push_back(p1);
        y.push_back(y1 % 100);
        s.push_back(s1);
    }

    sort(y.begin(), y.end());
    cout << y[0] << y[1] << y[2] << '\n';

    int max = max_element(p.begin(), p.end()) - p.begin();
    int min = min_element(p.begin(), p.end()) - p.begin();
    int mid;
    for (int i = 0; i < 3; i++) {
        if (i != max && i != min) mid = i;
    }
    cout << s[max][0] << s[mid][0] << s[min][0];
}