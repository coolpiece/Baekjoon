#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, M = 3000000000;
    cin >> n >> k;
    vector<long long> v1(n + 1);  // S > N
    vector<long long> v2(n + 1);  // N < S

    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
        v2[i] = v1[i] + i * k;
        v1[i] = v1[i] - i * k;
    }

    long long maxSN = -M, maxNS = -M, S1 = v1[1], N1 = v1[2], N2 = v2[1], S2 = v2[2];
    for (int i = 2; i <= n; i++) {
        maxSN = max(maxSN, v1[i] - S1); // 기존값 그대로 vs 현재값이 최댓값인 경우.
        S1 = min(S1, v1[i]);  // 현재까지 최솟값인 S1 선택. (다음 계산에 사용).

        maxNS = max(maxNS, N2 - v2[i]);  // 기존값 그대로 vs 현재값이 최솟값인 경우.
        N2 = max(N2, v2[i]); // 현재까지 최댓값인 N2 선택. (다음 계산에 사용).
    }
    cout << max(maxSN, maxNS);
}