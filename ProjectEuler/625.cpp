/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-11
 * Contest: Project Euler
 * Problem: 625
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const ll MOD = 998244353;
const ll MAX_N = 2e7 + 1; // > (10^10)^(1/2)
const ll PREF_N = MAX_N; // ~ (10^10)^(2/3)

vector <ll> prime;
bool is_composite[MAX_N];
ll phi[MAX_N];
ll prefphi[PREF_N];

void sieve (ll n) {
    fill(is_composite, is_composite + n, false);
	phi[1] = 1;
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.pb(i);
			phi[i] = i - 1;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}

/** DATASTRUCTURE: Floor Interval Array
 *  PURPOSE: Indexes critical values n/i
 *  SPACE: O(sqrt n)
*/
class FIVector {
    public:
        ll n;
        ll rt;
        ll len;
        ll startIndex;
        vector<ll> arr;
        vector<ll> keys;
    
        FIVector(ll num){
            n = num;
            rt = sqrt(num);
            len = 2 * rt;
            if (n/rt == rt){
                len--;
            }

            arr = vector<ll>(len);
            keys = vector<ll>(len);

            startIndex = len;

            for (ll i = 1; i <= rt; i++){
                keys[i - 1] = i;
                if (startIndex == len && i >= PREF_N){
                    startIndex = i - 1;
                }
            }

            bool found = (startIndex != len);

            for (ll i = 1; i <= rt; i++){
                keys[len - i] = n/i;
                if (!found && n/i >= PREF_N){
                    startIndex = len - i;
                }
            }
        }

        ll query(ll i){
            if (i < PREF_N){
                return prefphi[i];
            }

            if (i <= rt){
                return arr[i - 1];
            }

            return arr[len - n/i];
        }

        void set(ll i, ll x){
            if (i <= rt){
                arr[i - 1] = x;
                return;
            }

            arr[len - n/i] = x;
        }
};

FIVector sumphi(ll n, ll m){
    FIVector arr(n);

    for (int ii = arr.startIndex; ii < arr.keys.size(); ii++){
        ll key = arr.keys[ii];
        ll ans = 0;

        ll rt = sqrt(key);

        for (ll i = 1; i <= rt; i++){
            if (i != 1){
                ans += m - (arr.query(key/i) % m);
                ans %= m;
            }

            ans += m - ((phi[i] % m) * ((key/i) % m) % m);
            ans %= m;
        }

        ans += (arr.query(rt) * rt % m);
        ans %= m;

        if (key % 2 == 0){
            ans += (key/2 % m) * ((key + 1) % m) % m;
        } else {
            ans += (key % m) * ((key + 1)/2 % m) % m;
        }

        ans %= m;

        arr.set(key, ans);
    }

    return arr;
}

ll sum(ll n, ll m){
    if (n % 2 == 0){
        return (n/2 % m) * ((n + 1) % m) % m;
    } 
    
    return (n % m) * ((n + 1)/2 % m) % m;
}

void solve(){
    ll n = 1e11;

    sieve(min(n + 1, MAX_N));

    prefphi[1] = 1;
    for (ll i = 2; i < min(n + 1, PREF_N); i++){
        prefphi[i] = phi[i] + prefphi[i - 1];
        prefphi[i] %= MOD;
    }

    ll ans = 0;

    FIVector fi = sumphi(n, MOD);
    for (int i = 0; i < fi.keys.size(); i++){
        ll key = fi.keys[i];
        ll c = sum(n/key, MOD) - sum(n/(key + 1), MOD);
        c %= MOD;
        c *= fi.query(key);

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