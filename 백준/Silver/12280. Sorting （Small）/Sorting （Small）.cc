#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;
        vector<int> v(n), alex, bob;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2) { // index && worth save. odd.
                alex.push_back(v[i]);
                v[i] = 1;
            }
            else { // even.
                bob.push_back(v[i]);
                v[i] = 0;
            }
        }

        sort(alex.begin(), alex.end()); // sort.
        sort(bob.begin(), bob.end(), greater<int>());

        int idx0 = 0, idx1 = 0;
        for (int i = 0; i < n; i++) {
            if(v[i]) { // case 1 (alex).
                v[i] = alex[idx1];
                idx1++;
            }
            else { // case 2 (bob).
                v[i] = bob[idx0];
                idx0++;
            }
        }
        cout << "Case #" << k + 1 << ": "; // print.
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << '\n';
    }
}