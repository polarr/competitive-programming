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
    vi vals(n);
    vector<vi> a(n, vi(30, 0));
    vector<pii> b(30, {0, 0});
    rep(i, 0, n){
        int x;
        cin >> x;
        vals[i] = x;

        rep(j, 0, 30){
            if (x & (1 << j)){
                a[i][j] = 1;
                b[j].second++;
            } else {
                b[j].first++;
            }
        }
    }

    ll ans = 0;

    rep(i, 0, n){
        ll curr = 0;
        rep(j, 0, 30){
            if (a[i][j] == 1){
                curr += (ll)(b[j].first) * (ll)(1 << j);
            } else {
                curr += (ll)(b[j].second) * (ll)(1 << j);
            }
        }

        ans = max(curr, ans);
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