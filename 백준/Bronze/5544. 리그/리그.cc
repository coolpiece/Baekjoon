#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n + 1);  // 승점 저장
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c == d) {
            v[a]++;
            v[b]++;
        } else if (c > d)
            v[a] += 3;
        else
            v[b] += 3;
    }

    vector<pair<int, int>> score;  // 점수 저장.
    vector<int> rank(n + 1);       // 순위 만들기.
    for (int i = 1; i <= n; i++) {
        score.push_back({v[i], i});  // {승점, 인덱스}
    }
    sort(score.begin(), score.end(), greater<>());

    int r = 1, jump = 1;
    for (int i = 0; i < n - 1; i++) {
        while (score[i].first == score[i + 1].first) {
            rank[score[i].second] = r;
            jump++;
            i++;
        }
        if (jump > 1) {  // 같은 등수가 있는 경우.
            rank[score[i].second] = r;
            r += jump;
            jump = 1;
            continue;
        }

        if (score[i].first > score[i + 1].first) {
            rank[score[i].second] = r;
            r++;
        }
    }
    if(rank[score[n - 1].second] == 0) rank[score[n - 1].second] = r;

    for (int i = 1; i <= n; i++) cout << rank[i] << '\n';
}