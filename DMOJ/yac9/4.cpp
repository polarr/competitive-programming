/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-20
 * Contest: DMOJ yac9
 * Problem: 4
**/

// damn one-off error in the binomial coefficients really got me huh

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 3e6;
const ll MOD = 1e9 + 7;

/** ALGORITHM: Modular Exponentiation 
 *  PURPOSE: Computes x^n (mod m)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

vector<ll> fac(MAX_N + 1);
vector<ll> fac_inv(MAX_N + 1);
void factorial(ll p) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_N; i++) { fac[i] = fac[i - 1] * i % p; }
}
void factorial_inverses(ll p) {
    fac_inv[0] = 1;
	fac_inv[MAX_N] = mod_exp(fac[MAX_N], p - 2, p);
	for (int i = MAX_N; i >= 1; i--) { fac_inv[i - 1] = fac_inv[i] * i % p; }
}
ll choose(ll n, ll r, ll p) {
    if (r == 0){
        return 1;
    }
    if (n == 0){
        return 0;
    }
	return fac[n] * fac_inv[r] % p * fac_inv[n - r] % p;
}

void solve(){
    factorial(MOD);
    factorial_inverses(MOD);
    int n; cin >> n;
    int r; cin >> r;
    int x = 1, y = 0;
    bool still = true;
    for (int i = 2; i < n + 1; i++){
        int a; cin >> a;
        if (still && a == r){
            x = i;
        } else {
            still = false;
        }
    }
    still = true;
    for (int i = 1; i < n + 1; i++){
        int b; cin >> b;
        if (still && b == r){
            y = i;
        } else {
            still = false;
        }
    }

    // (x, y) = 1, do binomial grid sum

    if (y == 0){
        cout << choose(2 * n, n, MOD) << endl;
        return;
    }

    if (x == n && y == n){
        cout << 1 << endl;
        return;
    }

    if (x == n){
        cout << choose(x + n - y, x, MOD);
        return;
    }

    if (y == n){
        cout << choose(y + n - x, y, MOD);
        return;
    }

    // nontrivial grid sum
    ll ans = 0;
    for (int i = x + 1; i <= n; i++){
        ll c = choose(i - x + y, y, MOD);
        c *= choose(n - i + n - y - 1, n - i, MOD);
        c %= MOD;
        ans += c;
        ans %= MOD;
    }

    for (int i = y + 1; i <= n; i++){
        ll c = choose(i - y + x, x, MOD);
        c *= choose(n - i + n - x - 1, n - i, MOD);
        c %= MOD;
        ans += c;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}