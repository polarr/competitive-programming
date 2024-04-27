/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

vector<bool> is_prime(MAX_N, true);

vector<ll> primes;

void solve(){
    ll n;
    cin >> n;

    ll ans = 0;
    // j is prime
    /**
    for (int i = 1; i < n + 1; i++){
        for (int t = 0; t < primes.size(); t++){
            int j = primes[t];
            if (j > i){
                break;
            }

            int q = i/j;
            if (q % j != 0){
                // cout << i << " " << q << " " << j << endl;
                ans += j - (q % j);
                ans %= MOD;
            }
        }
    }
    **/

    for (int t = 0; t < primes.size(); t++){
        ll j = primes[t];
        if (j > n){
            break;
        }

        ll multr = (ll)n/(j * j);
        ll rem = n % (j * j);

        ans += (multr * j % MOD) * ((j * (j - 1)/2LL) % MOD) % MOD;
        ans %= MOD;

        ll mult = rem/j;
        if (mult == 0){
            continue;
        }
        ans += (j * ((mult - 1) * j - (mult - 1) * mult / 2)) % MOD;
        ans += ((rem + 1 - mult * j) * (j - mult)) % MOD;
        ans %= MOD;

        /**
        for (ll m = 1; m * j < rem + 1; m++){
            ll mult = j;

            if (m * j > rem - j){
                mult = rem + 1 - m * j;
            }

            if (m % j != 0){
                ans += mult * (j - (m % j));
                ans %= MOD;
            }
        }
        **/
    }

    ll mult = n/8;
    ans += 8 * mult;
    ans += max((n % 8) - 3, 0LL) * 2;
    ans %= MOD;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (ll i = 2; i < MAX_N; i++) {
		if (is_prime[i]) {
            primes.pb((ll)i);
			for (ll j = i * i; j < MAX_N; j += i) { is_prime[j] = false; }
		}
	}

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}