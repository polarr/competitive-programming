/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset - Mathematics
 * Problem: 1715
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

void solve(){
    vector<ll> fact(10e6 + 1, 1);
    for (int i = 2; i < fact.size(); i++){
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }

    string s; cin >> s;
    vector<ll> count(26, 0);
    for (int i = 0; i < s.size(); i++){
        count[s[i] - 'a']++;
    }

    ll ans = fact[s.size()];

    for (int i = 0; i < 26; i++){
        ans *= mod_exp(fact[count[i]], MOD - 2, MOD);
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