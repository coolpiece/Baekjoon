#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, str2, tmp;
    cin >> str >> tmp;
    str.append(tmp);
    swap(str[2], str[3]);
    str2 = str;
    swap(str2[1], str2[3]);

    if (!str.compare("HEPC") || !str.compare("CHEP") || !str.compare("PCHE") || !str.compare("EPCH")) cout << "YES";
    else if (!str2.compare("HEPC") || !str2.compare("CHEP") || !str2.compare("PCHE") || !str2.compare("EPCH")) cout << "YES";
    else
        cout << "NO";
}