#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	vector<int> score(n);
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	sort(score.begin(), score.end(), compare);
	cout << score[k - 1];
}
