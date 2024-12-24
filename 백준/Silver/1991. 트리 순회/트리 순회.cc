#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree(26, vector<int>(2));
void preorder(int current) {
    if (current == -1) return;
    cout << (char)(current + 'A');
    preorder(tree[current][0]);
    preorder(tree[current][1]);
}

void inorder(int current) {
    if (current == -1) return;
    inorder(tree[current][0]);
    cout << (char)(current + 'A');
    inorder(tree[current][1]);
}

void postorder(int current) {
    if (current == -1) return;
    postorder(tree[current][0]);
    postorder(tree[current][1]);
    cout << (char)(current + 'A');
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {  // 입력 받기.
        char cur, left, right;
        cin >> cur >> left >> right;
        int lidx = left - 'A', ridx = right - 'A';
        if (left == '.') lidx = -1;
        if (right == '.') ridx = -1;
        tree[cur - 'A'][0] = lidx;
        tree[cur - 'A'][1] = ridx;
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
}