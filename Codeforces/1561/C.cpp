/**
 * Solution by 1egend
 * Date: 8/24/2021
 * Contest: Codeforces Round 740 (Div 2)
 * Problem: C - 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector <vector<int>> caves;
    for (int i = 0; i < n; ++i){
        int k;
        cin >> k;
        int requirement = 0;
        for (int x = 0; x < k; ++x){
            int m;
            cin >> m;
            requirement = max<int>(requirement, m - x + 1);
        }
        vector <int> cave = {requirement, k};
        caves.pb(cave);
    }

    sort(caves.begin(), caves.end());
    int level = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans = max<int>(ans, caves[i][0] - level);
        level += caves[i][1];
    }
    cout << ans << endl;
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