#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

ll mod_exp(ll x, ll n, ll m){
    x %= m;
    ll res = 1;
    while (n > 0){
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }

    return res;
}

void solve() {
    ll n, k; cin >> n >> k;
    ll ans = n;

    ll inv = mod_exp(2 * k + 1, MOD - 2, MOD);

    // instead compute number of rooms which have only one player
    rep(i, 0, 2 * k){
        ans *= 2 * k;
        ans %= MOD;
        ans *= inv;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}