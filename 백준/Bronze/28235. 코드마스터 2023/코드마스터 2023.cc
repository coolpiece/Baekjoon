#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    if (!str.compare("SONGDO")) cout << "HIGHSCHOOL";
    else if (!str.compare("CODE")) cout << "MASTER";
    else if (!str.compare("2023")) cout << "0611";
    else if (!str.compare("ALGORITHM")) cout << "CONTEST";
}