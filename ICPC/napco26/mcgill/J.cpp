/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-19
 * Contest: 
 * Problem: J
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

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}
ull pollard(ull n) {
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ull x) { return modmul(x, x, n) + i; };
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
vector<ll> factor(ll n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ll x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

ll x;
vl good;
vl divs;
void divisors(vector<pair<ll, ll>> &div, int i, ll curr) {
    if (i == sz(div)) {
        ll q = curr + 1;
        divs.pb(curr);
        if (isPrime(q)) {
            good.pb(q);
        }
        return;
    }

    auto [p, e] = div[i];
    rep(j, 0, e + 1) {
        divisors(div, i + 1, curr);
        curr *= p;
    }
}

void solve(){
    cin >> x;
    vl d = factor(x);
    map<ll, ll> f;
    for (ll p : d) {
        f[p]++;
    }

    vector<pair<ll, ll>> div;
    for (auto [p, c] : f) {
        div.pb({p, c});
    }

    divisors(div, 0, 1);
    sort(all(divs));

    ll n = sz(good);
    ll m = sz(divs);
    vector<vl> dp(n + 1, vl(m));

    rep(i, 0, m) {
        dp[0][i] = (i == 0 ? 1 : LLONG_MAX);
    }

    auto idx = [&](ll d) {
        return lower_bound(all(divs), d) - divs.begin();
    };

    rep(i, 1, n + 1) {
        ll p = good[i - 1];
        rep(j, 0, m) {
            ll rem = divs[j];
            ll a = LLONG_MAX;
            ll mult = 1;
            ll r = rem;
            ll t = dp[i - 1][j];
            if (t != LLONG_MAX) a = min(a, mult * t);

            if (r % (p - 1) != 0) {
                dp[i][j] = a;
                continue;
            }

            r /= p - 1;
            while (true) {
                mult *= p;
                ll t = dp[i - 1][idx(r)];
                if (t != LLONG_MAX) a = min(a, mult * t);
                if (r % p != 0) {
                    break;
                }
                r /= p;
            }

            dp[i][j] = a;
        }
    }

    ll ans = dp[n][m - 1];

    if (ans == LLONG_MAX) {
        ans = -1;
    }

    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}