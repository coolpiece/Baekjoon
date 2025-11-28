#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        int flag = 0;
        vector<vector<int>> v(9, vector<int>(9));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) cin >> v[i][j];

        for (int i = 0; i < 9; i++) {
            if (flag) break;
            vector<int> col(10);
            for (int j = 0; j < 9; j++) {
                col[v[i][j]]++;
                if (col[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            if (flag) break;
            vector<int> row(10);
            for (int j = 0; j < 9; j++) {
                row[v[j][i]]++;
                if (row[v[j][i]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        vector<int> box(10);
        for (int i = 0; i < 3; i++) {
            if (flag) break;
            for (int j = 0; j < 3; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 3; i++) {
            if (flag) break;
            for (int j = 3; j < 6; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 3; i++) {
            if (flag) break;
            for (int j = 6; j < 9; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 3; i < 6; i++) {
            if (flag) break;
            for (int j = 0; j < 3; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 3; i < 6; i++) {
            if (flag) break;
            for (int j = 3; j < 6; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 3; i < 6; i++) {
            if (flag) break;
            for (int j = 6; j < 9; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 6; i < 9; i++) {
            if (flag) break;
            for (int j = 0; j < 3; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 6; i < 9; i++) {
            if (flag) break;
            for (int j = 3; j < 6; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        box = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 6; i < 9; i++) {
            if (flag) break;
            for (int j = 6; j < 9; j++) {
                box[v[i][j]]++;
                if (box[v[i][j]] > 1) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag)
            cout << "Case " << T << ": INCORRECT\n";
        else
            cout << "Case " << T << ": CORRECT\n";
    }
}