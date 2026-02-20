/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-16
 * Contest: 
 * Problem: D
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
    
ll euclid(ll a, ll b, ll &x, ll &y){
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}
    
ll crt(ll a, ll m, ll b, ll n){
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0){
        return LLONG_MAX;
    }
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x; 
}

void solve(){
    ll a, m, b, n; cin >> a >> m >> b >> n;
    ll k = m * n /__gcd(m, n);
    ll x = crt(a, m, b, n);
    if (x == LLONG_MAX) {
        cout << "no solution";
    } else {
        cout << x << " " << k;
    }

    cout << '\n';
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