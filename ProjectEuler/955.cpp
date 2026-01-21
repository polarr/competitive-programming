/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-21
 * Contest: Project Euler
 * Problem: 955
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using sll = __int128;
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

ll divAns = 0;
void maxDiv(vector<pair<ll, ll>> &div, int i, ll curr, ll mx) {
    divAns = max(divAns, curr);
    if (i == sz(div)) return;
    pair<ll, ll> p = div[i];
    rep(j, 0, p.second + 1) {
        if (j != 0) {
            if (curr > mx/p.first) break;
            curr *= p.first;
        }

        if (i == 0 && j != 1 && j != p.second - 1) continue;

        maxDiv(div, i + 1, curr, mx);
    }
}

sll read() {
    sll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(sll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve(){
    int num = 70;
    sll ans = 0;
    sll curr = 2;

    rep(i, 0, num - 1) {
        sll c = curr;
        sll prod = curr * (curr + 1) * 4;
        vl f = {2, 2};
        vl fc = factor(curr);
        for (ll d : fc) {
            f.pb(d);
        }
        fc = factor(curr + 1);
        for (ll d : fc) {
            f.pb(d);
        }
        vector<pair<ll, ll>> d;
        sort(all(f));
        int cnt = 0;
        rep(i, 0, sz(f)) {
            cnt++;
            if (i == sz(f) - 1 || f[i + 1] != f[i]) {
                d.pb({f[i], cnt});
                cnt = 0;
            }
        }

        divAns = 0;
        maxDiv(d, 0, 1, curr * 2 - 1);
        sll a = divAns;
        sll b = prod / a;
        sll k = (b - a)/2;
        sll nx = (a + b)/2;
        curr = (nx - 1)/2;
        ans += (k - 1)/2;
    }

    print(ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}