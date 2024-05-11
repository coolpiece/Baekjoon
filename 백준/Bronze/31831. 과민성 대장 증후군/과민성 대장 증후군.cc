#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
bool visited[1001][1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, count = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i<n; i++) {
        int a;
        cin>>a;
        v.push_back(a);
        if(i) v[i] += v[i - 1];
        if (v[i] < 0) v[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] >= m) count++;
    }
    cout<<count;
}