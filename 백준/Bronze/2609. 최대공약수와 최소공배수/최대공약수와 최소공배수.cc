#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
int GCD(int a, int b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int a, b, g, l;
	cin >> a >> b;
	g = GCD(a, b);
	a /= g;
	b /= g;
	l = a * b * g;
	cout << g << '\n' << l;
}

int GCD(int a, int b) { // 유클리드 호제법
	int M, m;
	if (a > b) M = a, m = b;
	else M = b, m = a;
	if (m == 0) return M;
	else return GCD(m, M % m);
}