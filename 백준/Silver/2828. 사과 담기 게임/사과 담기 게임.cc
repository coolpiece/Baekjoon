#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m, j, left, right, total=0;
	cin>>n>>m >> j;
	left = 1, right = m;
	for(int i=0; i<j; i++){
        int pos, move;
        cin>>pos;
		if(pos >= left && pos <= right) continue;
		else if(pos < left) {
			move = left - pos;
			left -= move;
			right -= move;
            total += move;
        }
		else {
			move = pos - right;
			left += move;
			right += move;
            total += move;
        }
	}
    cout << total;
}