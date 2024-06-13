#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string jae, doc;
    cin >> jae >> doc;
    if (jae.length() < doc.length())
        cout << "no";
    else
        cout << "go";
}