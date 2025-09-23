/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-22
 * Contest: Codeforces 2144
 * Problem: E1
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
const ll MOD = 998244353;

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi lseq, rseq, seq;
    int mx = 0;
    rep(i, 0, n){
        if (a[i] > mx){
            mx = a[i];
            seq.pb(a[i]);
            lseq.pb(a[i]);
        }
    }

    mx = 0;
    for (int i = n - 1; i >= 0; i--){
        if (a[i] > mx){
            mx = a[i];
            rseq.pb(a[i]);
        }
    }

    rseq.pop_back();

    for (int i = rseq.size() - 1; i >= 0; i--){
        seq.pb(rseq[i]);
    }

    int ml = lseq.size(), mr = rseq.size(), m = seq.size();

    ll dpl[n + 1][ml + 1], dpr[n + 1][mr + 1];
    rep(i, 0, n + 1){
        dpl[i][0] = 1;
        dpr[i][0] = 1;
    }
    rep(j, 1, ml + 1){
        dpl[0][j] = 0;
    }
    rep(j, 1, mr + 1){
        dpr[0][j] = 0;
    }

    rep(i, 1, n + 1){
        rep(j, 1, ml + 1){
            dpl[i][j] = dpl[i - 1][j];
            if (a[i - 1] == lseq[j - 1]){
                dpl[i][j] += dpl[i - 1][j - 1];
                dpl[i][j] %= MOD;
            }

            if (a[i - 1] <= lseq[j - 1]){
                dpl[i][j] += dpl[i - 1][j];
                dpl[i][j] %= MOD;
            }
        }
    }

    reverse(all(a));

    rep(i, 1, n + 1){
        rep(j, 1, mr + 1){
            dpr[i][j] = dpr[i - 1][j];
            if (a[i - 1] == rseq[j - 1]){
                dpr[i][j] += dpr[i - 1][j - 1];
                dpr[i][j] %= MOD;
            }

            if (a[i - 1] <= rseq[j - 1]){
                dpr[i][j] += dpr[i - 1][j];
                dpr[i][j] %= MOD;
            }
        }
    }

    reverse(all(a));

    ll ans = 0;
    rep(i, 0, n){
        if (a[i] != lseq[ml - 1]) continue;
        ans += (dpl[i + 1][ml] + MOD - dpl[i][ml]) % MOD * dpr[n - 1 - i][mr] % MOD;
        ans %= MOD;
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