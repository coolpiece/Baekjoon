#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, sum = 0;
    double avg;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    int cut = round(n * 0.15); // 제외할 사람 수
    v.erase(v.begin(), v.begin() + cut);
    v.erase(v.end() - cut, v.end());
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    if (sum == 0) { // 의견이 없는 경우
        avg = 0;
    }
    else {
        avg = (double) sum / v.size();
        avg = round(avg);
    }
    cout << avg;
}