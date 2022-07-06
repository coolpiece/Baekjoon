#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, count[10001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		count[num]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)
				cout << i << '\n';
		}
	}
}