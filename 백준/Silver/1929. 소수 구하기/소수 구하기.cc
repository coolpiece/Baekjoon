#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int m, n;
	cin >> m >> n;
	bool* check = new bool[n + 1]{ 1, 1,  };
	for (int i = 2; i * i <= n; i++) { // 제곱근으로 범위 생각
		if (!check[i]) {
			for (int j = i * 2; j <= n; j += i) // 합성수 true로
				check[j] = true;
		}
	}
	for (int i = m; i <= n; i++)
		if (!check[i]) cout << i << '\n';

}