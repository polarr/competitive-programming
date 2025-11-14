/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-13
 * Contest: 
 * Problem: E
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
    int n, k, x; cin >> n >> k >> x;

    vi friends(n + 2);

    rep(i, 0, n) {
        cin >> friends[i];
    }

    friends[n] = -1e9;
    friends[n + 1] = 2e9;

    sort(all(friends));
    
    int lo = 0, hi = x;
    while (lo < hi){
        int mid = (lo + hi + 1)/2;
        
        int put = 0;
        rep(i, 0, n + 1){
            int l = max(0, friends[i] + mid);
            int r = min(x, friends[i + 1] - mid);

            put += max(0, r - l + 1);
        }

        if (put >= k){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    vi ans;

    if (lo == 0){
        rep(i, 0, k){
            ans.pb(i);
        }
    } else {
        rep(i, 0, n + 1){
            int l = max(0, friends[i] + lo);
            int r = min(x, friends[i + 1] - lo);

            rep(j, l, r + 1){
                ans.pb(j);
                if (sz(ans) == k) break;
            }

            if (sz(ans) == k) break;
        }
    }

    rep(i, 0, k){
        cout << ans[i] << " ";
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