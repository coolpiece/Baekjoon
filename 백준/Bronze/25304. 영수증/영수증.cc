#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int x, n, sum = 0;
	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}
	x == sum ? cout << "Yes" : cout << "No";
}