#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    vector<pair<int, string>> teamname;
    long long n, nl = 0, no = 0, nv = 0, ne = 0, max = -1;
    cin >> name >> n;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'L')
            nl++;
        else if (name[i] == 'O')
            no++;
        else if (name[i] == 'V')
            nv++;
        else if (name[i] == 'E')
            ne++;
    }

    for (int i = 0; i < n; i++) {
        string team;
        cin >> team;
        long long l = nl, o = no, v = nv, e = ne, score;
        for (int j = 0; j < team.size(); j++) {
            if (team[j] == 'L')
                l++;
            else if (team[j] == 'O')
                o++;
            else if (team[j] == 'V')
                v++;
            else if (team[j] == 'E')
                e++;
        }
        score = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
        teamname.push_back({score, team});
    }
    sort(teamname.begin(), teamname.end(), compare);

    for(int i=0; i<n; i++) {
        // cout << teamname[i].second << ": " << teamname[i].first << '\n';
    }
    cout << teamname[0].second;
}