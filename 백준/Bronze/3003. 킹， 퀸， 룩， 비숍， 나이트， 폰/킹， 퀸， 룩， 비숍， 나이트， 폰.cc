#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<int> n(6), cnt = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++) {
		cin >> n[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << cnt[i] - n[i] << " ";
	}
}