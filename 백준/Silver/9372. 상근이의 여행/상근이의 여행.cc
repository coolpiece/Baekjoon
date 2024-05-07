#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
        }
        cout << n - 1 << '\n';  // 항상 연결 그래프이므로 모든 정점이 연결되어있음. -> 비행기 종류의 수와 관계없이 n-1번 탑승해야 모두 여행 가능.
    }
}