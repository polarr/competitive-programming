/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
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
    vector<vector<int>> pts(2, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        pts[y][x] = 1;
    }

    ll ans = 0;

    for (int i = 0; i < n + 1; i++){
        if (pts[0][i] && pts[1][i]){
            ans += (ll)(n - 2);
        }

        if (i == 0 || i == n){
            continue;
        }

        ans += (ll) pts[1][i] && pts[0][i - 1] && pts[0][i + 1];
        ans += (ll) pts[0][i] && pts[1][i - 1] && pts[1][i + 1];
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