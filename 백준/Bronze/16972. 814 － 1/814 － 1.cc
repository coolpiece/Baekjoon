#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    random_device rd;
    mt19937 mersenne(rd());
    uniform_int_distribution<> die(-8140, 8140);

    for (int i = 0; i < 814; i++) {
        cout << die(mersenne) << " " << die(mersenne) << '\n';
    }
}