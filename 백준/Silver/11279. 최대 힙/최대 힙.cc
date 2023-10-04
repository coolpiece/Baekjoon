#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, level = 1;
    vector<int> v = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {  // 출력 및 삭제.
            if (v.size() == 1) {
                cout << "0\n";
            }
            else {
                cout << v[1] << '\n';    // 가장 큰 값 출력.
                v[1] = v[v.size() - 1];  // 마지막 노드 값 루트 노드로 이동.
                v.pop_back();
                int idx = 1;
                while (idx * 2 <= v.size() - 1) {
                    if (idx * 2 + 1 <= v.size() - 1 && v[idx * 2] < v[idx * 2 + 1] && v[idx] < v[idx * 2 + 1]) { // 오른쪽 노드가 있는 경우.
                        swap(v[idx], v[idx * 2 + 1]);
                        idx *= 2;
                        idx++;
                    }
                    else if (v[idx] < v[idx * 2]) {
                        swap(v[idx], v[idx * 2]);
                        idx *= 2;
                    }
                    else
                        break;
                }
            }
        }
        else {  // 삽입.
            v.push_back(x);
            int idx = v.size() - 1;
            while (idx != 1) {
                if (v[idx] > v[idx / 2]) {  // 자식 노드가 부모 노드보다 큰 경우 자리 교환.
                    swap(v[idx], v[idx / 2]);
                    idx /= 2;
                }
                else {
                    break;
                }
            }
        }
    }
}