#include <bits/stdc++.h>
using namespace std;

int main(void) {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string S, K, sub;
cin >> S >> K;
for (int i = 0; i < S.size(); i++) {
    if (S[i] >= '0' && S[i] <= '9')
        continue;
    else
        sub.push_back(S[i]);
}
if (sub.find(K) != sub.npos)
    cout << 1;
else
    cout << 0;
}