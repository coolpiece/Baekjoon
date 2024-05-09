#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
bool visited[1001][1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1) {
        int count = 0;
        string str;
        getline(cin, str);
        if (!str.compare("#")) break;
        int length = str.size();
        for (int i = 0; i < length; i++) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') count++;
        }
        cout << count << '\n';
    }
}