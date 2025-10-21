/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-20
 * Contest: Codeforces 2145
 * Problem: F
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

// kind of simple?
void solve(){
    ll n, m; cin >> n >> m;

    ll k = 1;
    vector<pii> traps(n);
    rep(i, 0, n){
        cin >> traps[i].second;
        k = lcm(k, traps[i].second);
    }

    rep(i, 0, n){
        cin >> traps[i].first;
    }

    int lg = log2(m) + 1;
    vector<vector<pll>> to(k, vector<pll>(lg));

    rep(i, 0, k){
        int curr = i;
        rep(j, 0, n){
            int nx = curr + 1;
            auto [r, p] = traps[j];
            if (nx % p != r){
                curr++;
            }
        }

        to[i][0] = {curr % k, curr - i};
    }

    rep(j, 1, lg){
        rep(i, 0, k){
            pll x = to[i][j - 1];
            pll y = to[x.first][j - 1];
            
            to[i][j] = {y.first, x.second + y.second};
        }
    }

    ll ans = 0;
    ll at = 0;
    int curr = 0;
    for (int i = lg - 1; i >= 0; i--){
        if (at + to[curr][i].second < m){
            at += to[curr][i].second;
            ans += n * (1LL << i);
            curr = to[curr][i].first;
        }
    }

    rep(i, 0, n){
        if (at == m) break;

        int nx = curr + 1;
        auto [r, p] = traps[i];
        if (nx % p != r){
            curr = (curr + 1) % k;
            at++;
        }

        ans++;
    }

    if (at != m){
        cout << -1 << endl;
        return;
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