/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-18
 * Contest: CSES Problemset
 * Problem: 3355
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e7 + 1;
const ll MOD = 1e9 + 7;

vector<pii> ans(MAX_N, {-1, -1});

void solve(){
    int n; cin >> n;

    rep(i, 0, n + 1){
        if (ans[i].first != -1 && ans[n - i].first != -1){
            cout << ans[i].first << " " << ans[i].second << " " << ans[n - i].first << " " << ans[n - i].second << endl;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int x = 0; x * x < MAX_N; x++){
        for (int y = 0; x * x + y * y < MAX_N; y++){
            int c = x * x + y * y;
            ans[c] = {x, y};
        }
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}