/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-12
 * Contest: Codeforces 2055
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    
    vector<vector<ll>> grid(n, vector<ll>(m));
    
    vector<ll> rows(n, 0);
    vector<set<int>> countr(n);
    vector<ll> cols(m, 0);
    vector<set<int>> countc(m);

    string s; cin >> s;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }

    vector<vector<ll>> ans = grid;

    int r = 0, c = 0;
    countr[r].insert(c);
    countc[c].insert(r);
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'D'){
            r++;
        } else {
            c++;
        }

        countr[r].insert(c);
        countc[c].insert(r);
    }

    set<array<int, 3>> greedy;

    for (int i = 0; i < n; i++){
        greedy.insert({countr[i].size(), 0, i});    
    }

    for (int i = 0; i < m; i++){
        greedy.insert({countc[i].size(), 1, i});
    }

    while (greedy.size() > 1){
        array<int, 3> top = *greedy.begin();
        if (top[1] == 0){
            int r = top[2];
            int c = *countr[r].begin();

            ans[r][c] = -rows[r];
            rows[r] = 0;
            cols[c] += ans[r][c];
            countr[r].erase(c);

            greedy.erase({countc[c].size(), 1, c});
            countc[c].erase(r);
            greedy.insert({countc[c].size(), 1, c});
        } else {
            int c = top[2];
            int r = *countc[c].begin();

            ans[r][c] = -cols[c];
            cols[c] = 0;
            rows[r] += ans[r][c];
            countc[c].erase(r);

            greedy.erase({countr[r].size(), 0, r});
            countr[r].erase(c);
            greedy.insert({countr[r].size(), 0, r});
        }

        greedy.erase(top);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}