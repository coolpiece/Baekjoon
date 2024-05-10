#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
bool visited[1001][1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        string str;
        int age, weight;
        cin >> str >> age >> weight;
        if (!str.compare("#")) break;
        if (age > 17 || weight >= 80)
            cout << str << " Senior\n";
        else
            cout << str << " Junior\n";
    }
}