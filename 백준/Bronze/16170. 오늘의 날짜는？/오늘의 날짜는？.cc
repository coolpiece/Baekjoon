#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto timer = time(NULL);
    auto t = localtime(&timer);
    vector<int> d = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    t->tm_hour -= 9;
    
    if (t->tm_hour < 0) t->tm_mday--;

    if (t->tm_mday <= 0) {
        t->tm_mon--;
        if (t->tm_mon < 0) {
            t->tm_mon += 12;
            t->tm_year--;
        }
        t->tm_mday += d[t->tm_mon];
    }

    cout << t->tm_year + 1900 << '\n' << t->tm_mon + 1 << '\n' << t->tm_mday;
}