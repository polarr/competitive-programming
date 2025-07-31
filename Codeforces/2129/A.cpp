/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-31
 * Contest: 
 * Problem: A
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    map<int, int> mp1, mp2;
    vector<pii> pairs(n);
    rep(i, 0, n){
        cin >> pairs[i].first >> pairs[i].second;
        int best = pairs[i].second;
        if (mp1.contains(pairs[i].first)){
            best = max(best, mp1[pairs[i].first]);
        }
        mp1[pairs[i].first] = best;
        best = pairs[i].first;
        if (mp2.contains(pairs[i].second)){
            best = min(best, mp2[pairs[i].second]);
        }

        mp2[pairs[i].second] = best;
    }

    vi ans;
    rep(i, 0, n){
        if (mp1[pairs[i].first] == pairs[i].second && mp2[pairs[i].second] == pairs[i].first){
            ans.pb(i);
        }
    }

    cout << ans.size() << endl;

    rep(i, 0, ans.size()){
        cout << ans[i] + 1 << " ";
    }

    cout << endl;
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