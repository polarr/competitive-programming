/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-04
 * Contest: CSES Problemset - Mathematics
 * Problem: 2209
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

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

vector<pair<int, int>> factor(int n, vector<int>& k){
    int kk = 1;
	vector<pair<int, int>> ans;
	for (int i = 2; i * i <= n; i++) {
        int a = 0;
		while (n % i == 0) {
            a++;
			n /= i;
		}

        if (a > 0){
            k.pb(kk);
            ans.pb({i, a});
            kk *= a + 1;
        }
	}
	if (n > 1) { k.pb(kk); ans.pb({n, 1}); kk *= 2;}
    k.pb(kk);
	return ans;
}

int totient(vector<pair<int, int>>& fn, vector<pair<int, int>>& fd){
    ll ans = 1;
    for (int i = 0; i < fn.size(); i++){
        int p = fn[i].first;
        int a = fn[i].second - fd[i].second;
        if (a == 0){continue;}
        ans *= mod_exp(p, a - 1, MOD);
        ans %= MOD;
        ans *= p - 1;
        ans %= MOD;
    }
    return ans;
}

void solve(){
    ll n, m; cin >> n >> m;

    vector<int> k;
    vector<pair<int, int>> f = factor(n, k);
    int fs = f.size();

    ll s = 0;

    for (int i = 0; i < k[fs]; i++){
        int dd = 1;
        vector<pair<int, int>> d(fs);
        for (int j = 0; j < fs; j++){
            d[j] = {f[j].first, (i/k[j]) % (f[j].second + 1)};
            dd *= mod_exp(d[j].first, d[j].second, MOD);
        }

        s += (totient(f, d) * mod_exp(m, dd, MOD)) % MOD;
        s %= MOD;
    }

    /**
    
    vector<ll> pow_m(n + 1, 1);
    for (int i = 1; i < n + 1; i++){
        pow_m[i] = (pow_m[i - 1] * m);
        pow_m[i] %= MOD;
    }

    ll s = 0;
    for (int i = 1; i <= n; i++){
        // rotate i, contribution simply m^gcd(i, n)
        ll g = gcd(i, n);
        s += pow_m[g];
        s %= MOD;
    }

    // done by burnside's, actually you can optimize this to O(sqrt(n)) by prime factoring n, summing over divisors and thus getting rid of gcd
    **/


    ll ans = (s * mod_exp(n, MOD - 2, MOD)) % MOD;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}