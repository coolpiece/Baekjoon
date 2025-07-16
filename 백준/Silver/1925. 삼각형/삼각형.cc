#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    vector<double> v(3);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((double)(x1 - x2) / (y1 - y2) == (double)(x2 - x3) / (y2 - y3))
        cout << "X";
    else {
        v[0] = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        v[1] = pow(x2 - x3, 2) + pow(y2 - y3, 2);
        v[2] = pow(x3 - x1, 2) + pow(y3 - y1, 2);
        sort(v.begin(), v.end());

        if (v[0] == v[1] && v[1] == v[2])
            cout << "JungTriangle";
        else if (v[0] == v[1] || v[1] == v[2]) {
            if ((v[0] + v[1]) < v[2])
                cout << "Dunkak2Triangle";
            else if ((v[0] + v[1]) == v[2])
                cout << "Jikkak2Triangle";
            else
                cout << "Yeahkak2Triangle";
        } else {
            if ((v[0] + v[1]) < v[2])
                cout << "DunkakTriangle";
            else if ((v[0] + v[1]) == v[2])
                cout << "JikkakTriangle";
            else
                cout << "YeahkakTriangle";
        }
    }
}