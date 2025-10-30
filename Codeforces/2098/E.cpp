#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using ld = long double;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
    
ll mod_exp(ll x, ll n, ll m){
    x %= m;
    ll res = 1;
    while (n > 0){
        if (n % 2 == 1) {res = res * x % m;}
        x = x * x % m;
        n /= 2;
    }
    
    return res;
}
    
ll euclid(ll a, ll b, ll &x, ll &y){
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}
    
ll inv(ll x, ll m){
    ll ans, useless;
    euclid(x, m, ans, useless);
    if (ans < 0){
        return (m + (ans % m)) % m;
    }
    return ans;
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
    
pair<ld, ld> transform(ld a, ld b){
    return pair<ld, ld>{(a + b)/2, (-a + b)/2};
}
    
void solve() {
    ll n, x, y, vx, vy; cin >> n >> x >> y >> vx >> vy;
    
    ll g = gcd(vx, vy);
    vx /= g;
    vy /= g;
    
    ll g1 = gcd(n, vx);
    ll g2 = gcd(n, vy);
    
    if (x % g1 != 0 || y % g2 != 0){
        cout << -1 << endl;
        return;
    }
    
    ll a = (n - x) / g1 * inv(vx/g1, n/g1) % (n/g1);
    ll b = (n - y) / g2 * inv(vy/g2, n/g2) % (n/g2);
    ll t = crt(a, n/g1, b, n/g2);
    //cout << a << " " << n/g1 << " " << b << " " << n/g2 << endl;
    
    if (t == LLONG_MAX){
        cout << -1 << endl;
        return;
    }
    
    ll xx = (t * vx + x)/n;
    ll yy = (t * vy + y)/n;
    
    ll ans = xx + yy - 2LL;
    xx++;
    pair<ld, ld> end = transform(xx, yy);
    if (end.second >= 0){
        ans += ceil(end.second);
    } else {
        ans += ceil(-end.second - 1);
    }

    if (end.first >= 1){
        ans += ceil(end.first) - 1;
    } else {
        ans += ceil(-end.first + 1) - 1;
    }
    
    cout << ans << endl; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}