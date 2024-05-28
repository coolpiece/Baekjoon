#include <bits/stdc++.h>
using namespace std;

vector<int> a(10000);
int n, k, cnt = 0;

int partition(int p, int r) {
    int x, i, tmp;
    x = a[r];  // pivot.
    i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
            cnt++;
            if (cnt == k) {
                cout << a[i] << ' ' << a[j] << '\n';
                return (-1);
            }
        }
    }
    if (i + 1 != r) {
        swap(a[r], a[i + 1]);
        cnt++;
        if (cnt == k) {
            cout << a[i + 1] << ' ' << a[r] << '\n';
            return (-1);
        }
    }
    return i + 1;
}

void quick_sort(int p, int r) { // int형 리턴하면 메모리 초과. -> void형으로 변경.
    int q;
    if (p < r) {
        q = partition(p, r);
        if (q == -1) return;
        quick_sort(p, q - 1);
        quick_sort(q + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    quick_sort(0, n - 1);
    if (cnt < k) cout << -1;
}