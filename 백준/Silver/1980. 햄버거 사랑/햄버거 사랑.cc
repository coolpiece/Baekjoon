#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t, ham = 0, coke = 10000;
    cin >> n >> m >> t;
    if (n < m) swap(n, m);  // n > m.
    for (int i = 0; i <= t / n; i++) {
        int j = (t - n * i) / m;         // i: m의 개수, j: n의 개수.
        if (coke > t - n * i - m * j) {  // 콜라를 마시는 시간이 최소인 경우.
            coke = t - n * i - m * j;
            ham = i + j;
        } else if (coke == t - n * i - m * j) {  // 콜라를 마시는 시간이 같으면, 햄버거를 더 많이 먹는 경우 선택.
            ham = max(ham, i + j);
        }
    }
    cout << ham << " " << coke;
}