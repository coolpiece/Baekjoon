#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >>m;
    vector<int> customer(n);
    vector<int> product(m);
    for(int i=0; i<n; i++) cin >> customer[i];
    for(int i=0; i<m; i++) cin >> product[i];
    sort(customer.begin(), customer.end(), greater<>());
    sort(product.begin(), product.end());

    long long rst = 0;
    if(n >= m) {
        for(int i=0; i<m; i++) {
            long long cal = max(0, customer[i] - product[i]);
            rst += cal;
        }
    }
    else {
        for(int i=0; i<n; i++) {
            long long cal = max(0, customer[i] - product[i]);
            rst += cal;
        }
    }
    cout << rst;
    return 0;
}