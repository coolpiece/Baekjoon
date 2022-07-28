#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str;
	cin >> str;
	vector<string> v;
	int l = str.length();
	for (int i = 0; i < l; i++) {
		v.push_back(str);
		str.erase(0, 1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
}