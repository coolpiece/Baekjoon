#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	if (n % 7 == 1 || n % 7 == 3) cout << "CY" << "\n";
	else cout << "SK" << "\n";
}