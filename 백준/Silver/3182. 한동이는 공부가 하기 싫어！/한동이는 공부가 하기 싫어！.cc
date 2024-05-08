#include <bits/stdc++.h>
using namespace std;
int dfs(int, int);

vector<int> v;
bool visited[1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    for (int i = 0; i < n; i++) {
        int length = 0;
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        length = dfs(v[i] - 1, length);
        if (length > max) {
            max = length;
            num = i + 1;
        }
    }
    cout << num;
}

int dfs(int num, int length) {
    visited[num] = true;
    length++;
    if (!visited[v[num] - 1]) length = dfs(v[num] - 1, length);
    return length;
}