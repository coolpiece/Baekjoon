#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, flag = 0;
    string str1, str2, tmp1 = "", tmp2 = "";
    vector<int> v(5);  // a, e, i, o, u 개수 저장.
    cin >> n >> str1 >> str2;
    if (str1[0] != str2[0]) flag = 1; // 첫 글자는 동일해야 함.
    if (str1[n - 1] != str2[n - 1]) flag = 1; // 마지막 글자는 동일해야 함.

    for (int i = 0; i < n; i++) {
        switch (str1[i]) {
            case 'a':
                v[0]++;
                break;
            case 'e':
                v[1]++;
                break;
            case 'i':
                v[2]++;
                break;
            case 'o':
                v[3]++;
                break;
            case 'u':
                v[4]++;
                break;
            default:  // 자음인 경우
                tmp1 += str1[i];
                break;
        }

        switch (str2[i]) {
            case 'a':
                v[0]--;
                break;
            case 'e':
                v[1]--;
                break;
            case 'i':
                v[2]--;
                break;
            case 'o':
                v[3]--;
                break;
            case 'u':
                v[4]--;
                break;
            default:  // 자음인 경우
                tmp2 += str2[i];
                break;
        }
    }

    if (tmp1.compare(tmp2)) flag = 1; // 모음을 제거한 문자열이 다른 경우.

    for (int i = 0; i < 5; i++) { // 모음의 개수가 같아야 함.
        if (v[i]) {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "NO";
    else
        cout << "YES";
}