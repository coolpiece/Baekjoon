#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int t, round = 0;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y, z, cnt = 0;
		cin >> x >> y >> z;
		if (x % 2 != 0) cnt++;
		if (y % 2 != 0) cnt++;
		if (z % 2 != 0) cnt++;
		if (cnt >= 2) cout << "B" << "\n";
		else cout << "R" << "\n";
	}
}
