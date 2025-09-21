/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Project Euler
 * Problem: 700
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

const int MAX_N = 1e8 + 1;
const ll MOD = 4503599627370517;

/** 
 * ALGORITHM: Modular Exponentiation 
 * PURPOSE: Computes x^n (mod m)
 * CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 * TIME: O(log n)
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
    ll x = 1504170715041707;
    ll inv = 3451657199285664;
    ll mn = LLONG_MAX;
    ll curr = 0;
    ll ans = 0;
    map<int, bool> mp;
    rep(i, 1, 42298633 + 1){
        curr += x;
        curr %= MOD;
        if (curr < mn){
            mn = curr;
            mp[curr] = true;
            ans += curr;
        }
    }

    curr = 0;
    mn = LLONG_MAX;
    rep(i, 1, 15806432 + 1){
        curr += inv;
        curr %= MOD;
        if (curr < mn){
            mn = curr;
            if (!mp[i]){
                ans += i;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}