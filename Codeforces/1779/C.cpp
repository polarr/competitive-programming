/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-20
 * Contest: Codeforces 1779
 * Problem: C
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
    int n, m; cin >> n >> m;
    vl a(n);
    rep(i, 0, n) cin >> a[i];

    --m;
    int ans = 0;
    ll curr = 0;
    multiset<ll> negs;
    rep(i, m + 1, n){
        if (a[i] < 0){
            negs.insert(a[i]);
        }
        curr += a[i];
        while(curr < 0){
            curr -= 2LL * *negs.begin();
            negs.erase(negs.begin());
            ans++;
        }
    }

    curr = 0;
    multiset<ll> pos;
    for (int i = m; i >= 1; i--){
        if (a[i] > 0){
            pos.insert(a[i]);
        }
        curr += a[i];
        while (curr > 0){
            curr -= 2LL * *prev(pos.end());
            pos.erase(prev(pos.end()));
            ans++;
        }
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