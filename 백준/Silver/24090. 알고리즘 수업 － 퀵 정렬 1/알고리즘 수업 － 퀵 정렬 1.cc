#include <bits/stdc++.h>
using namespace std;
int n, k, cnt = 0;

int partition(int arr[], int p, int r) {
    int x, i, tmp;
    x = arr[r];  // pivot.
    i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            tmp = arr[j];
            arr[j] = arr[++i];
            arr[i] = tmp;
            cnt++;
            if (cnt == k) {
                cout << arr[i] << ' ' << arr[j] << '\n';
                return (-1);
            }
        }
    }
    if (i + 1 != r) {
        tmp = arr[r];
        arr[r] = arr[i + 1];
        arr[i + 1] = tmp;
        cnt++;
        if (cnt == k) {
            cout << arr[i + 1] << ' ' << arr[r] << '\n';
            return (-1);
        }
    }
    return i + 1;
}

void quick_sort(int arr[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(arr, p, r);
        if (q == -1) return;
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    if (cnt < k) cout << -1;

    delete[] arr;
}