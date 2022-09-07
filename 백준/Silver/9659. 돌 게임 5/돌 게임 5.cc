#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	long long n;
	cin >> n;
	if (n % 2 == 0) cout << "CY" << "\n";
	else cout << "SK" << "\n";
}