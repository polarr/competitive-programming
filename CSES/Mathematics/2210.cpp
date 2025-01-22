/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-21
 * Contest: CSES Problemset
 * Problem: 2210
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
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

void solve(){
    ll n; cin >> n;
    if (n == 1){
        cout << 2 << endl;
        return;
    }
    ll ans = 0;
    ll a = n * n;
    ll b = (a + 1)/2;
    ll c = ((n + 1)/2) * ((n + 1)/2);
    if (n % 2 == 1){
        ll k = n/2;
        c = k * k + k + 1;
    }
    ans += mod_exp(2, a - 2, MOD);
    ans %= MOD;
    ans += mod_exp(2, b - 2, MOD);
    ans %= MOD;
    ans += mod_exp(2, c - 1, MOD);
    ans %= MOD;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}