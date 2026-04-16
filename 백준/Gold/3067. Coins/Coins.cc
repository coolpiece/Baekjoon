#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    int n, m;
    cin >> n;
    vector<int> coins(n + 1);  // 동전 입력 받기.
    for (int i = 1; i <= n; i++) cin >> coins[i];

    cin >> m;
    vector<int> cost(m + 1);
    cost[0] = 1;  // 0원을 만드는 방법 1가지.
    for (int i = 1; i <= n; i++) {
      // coins[i]원을 사용하여 j원을 만드는 경우 + 사용하지 않고 만드는 경우.
      for (int j = coins[i]; j <= m; j++) cost[j] += cost[j - coins[i]];
    }
    cout << cost[m] << '\n';
  }
}

/*
// 이전 방식. 2차원 배열 -> 1차원 배열로 개선.
int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int T = 0; T < t; T++) {
    int n, m;
    cin >> n;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> coins[i];
    sort(coins.begin(), coins.end()); // 금액 오름차순 정렬.

    cin >> m;
    // // ans[i][j]: i번째 동전까지 사용하여 j원을 만들 수 있는 방법의 수.
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      ans[i][0] = 1;
      for (int j = 1; j <= m; j++) {
        ans[i][j] = ans[i - 1][j]; // i번째 동전을 사용하지 않는 경우.
        if (j - coins[i] >= 0)     // i번째 동전을 사용하는 경우.
          ans[i][j] += ans[i][j - coins[i]];
      }
    }
    cout << ans[n][m] << '\n';
  }
}
*/