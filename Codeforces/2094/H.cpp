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
    int n, q; cin >> n >> q;

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    // vi b;
    // vi make(n + 1);
    // int cnt = 0;
    // rep(i, 0, n){
    //     if (i > 0 && a[i] != a[i - 1]){
    //         cnt++;
    //         b.pb(a[i]);
    //     }

    //     make[i] = cnt;
    // }

    // make[n] = cnt + 1;
    
    vector<vector<int>> has(MAX_N);

    vector<vector<pii>> queries(n + 1);
    vl ans(q);
    rep(i, 0, q){
        int k, l, r; cin >> k >> l >> r;
        --l;
        queries[l].pb({k, i});
        queries[r].pb({-1, i});
    }

    vector<bool> gone(q, false);
    vl change(q, -1);
    vl curr(q, -1);

    rep(i, 0, n + 1){
        for (auto &[v, idx] : queries[i]){
            if (v == -1){
                gone[idx] = true;
                ans[idx] += curr[idx] * (ll)(i - change[idx]);
            } else {
                has[v].pb(idx);
                curr[idx] = v;
                change[idx] = i;
            }
        }

        if (i == n) continue;

        for (int j = a[i]; j < MAX_N; j += a[i]){
            for (int idx : has[j]){
                if (gone[idx]) continue;
                int jj = j;
                while (jj % a[i] == 0){
                    jj /= a[i];
                }

                has[jj].pb(idx);
                ans[idx] += curr[idx] * (ll)(i - change[idx]);
                curr[idx] = jj;
                change[idx] = i;
            }

            has[j] = {};
        }
    }

    for (ll a : ans){
        cout << a << endl;
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