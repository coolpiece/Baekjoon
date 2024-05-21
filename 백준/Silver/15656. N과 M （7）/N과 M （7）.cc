#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v(7);
vector<int> output(7);

void backtracking(int cnt) {
    if (cnt == M) { // M개를 다 고른 경우.
        for (int i = 0; i < M; i++) {
            cout << output[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        output[cnt] = v[i];
        backtracking(cnt + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.begin() + N);
    backtracking(0);
}