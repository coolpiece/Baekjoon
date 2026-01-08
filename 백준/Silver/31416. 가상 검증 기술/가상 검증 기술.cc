#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int ta, tb, va, vb, t1, t2;
		cin >> ta >> tb >> va >> vb;
		t1 = tb * vb;
		va -= t1 / ta;
		t2 = t1 / ta * ta;
		if (va > 0) {
			int rst = 100000;
			for (int j = 0; j <= va; j++) {
				int tmp = max(t1 + ta * j, t2 + ta * (va - j));
				rst = min(rst, tmp);
			}
			cout << rst << '\n';
		}
		else cout << t1 << '\n';
	}
	return 0;
}