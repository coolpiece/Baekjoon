#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string c1, c2, c3;
    int n1, n2, n3;
    cin >> c1 >> c2 >> c3;
    if (!c1.compare("black"))
        n1 = 0;
    else if (!c1.compare("brown"))
        n1 = 1;
    else if (!c1.compare("red"))
        n1 = 2;
    else if (!c1.compare("orange"))
        n1 = 3;
    else if (!c1.compare("yellow"))
        n1 = 4;
    else if (!c1.compare("green"))
        n1 = 5;
    else if (!c1.compare("blue"))
        n1 = 6;
    else if (!c1.compare("violet"))
        n1 = 7;
    else if (!c1.compare("grey"))
        n1 = 8;
    else if (!c1.compare("white"))
        n1 = 9;

    if (!c2.compare("black"))
        n2 = 0;
    else if (!c2.compare("brown"))
        n2 = 1;
    else if (!c2.compare("red"))
        n2 = 2;
    else if (!c2.compare("orange"))
        n2 = 3;
    else if (!c2.compare("yellow"))
        n2 = 4;
    else if (!c2.compare("green"))
        n2 = 5;
    else if (!c2.compare("blue"))
        n2 = 6;
    else if (!c2.compare("violet"))
        n2 = 7;
    else if (!c2.compare("grey"))
        n2 = 8;
    else if (!c2.compare("white"))
        n2 = 9;

    if (!c3.compare("black"))
        n3 = 0;
    else if (!c3.compare("brown"))
        n3 = 1;
    else if (!c3.compare("red"))
        n3 = 2;
    else if (!c3.compare("orange"))
        n3 = 3;
    else if (!c3.compare("yellow"))
        n3 = 4;
    else if (!c3.compare("green"))
        n3 = 5;
    else if (!c3.compare("blue"))
        n3 = 6;
    else if (!c3.compare("violet"))
        n3 = 7;
    else if (!c3.compare("grey"))
        n3 = 8;
    else if (!c3.compare("white"))
        n3 = 9;

    if (n1 == 0) {
        if (n2 == 0) {
            cout << 0;
            exit(0);
        } else {
            cout << n2;
        }
    } else
        cout << n1 << n2;
    for (int i = 0; i < n3; i++) cout << 0;
}