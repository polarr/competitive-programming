/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-02
 * Contest: DMOJ math
 * Problem: 16
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const ll MAX_N = 6e6 + 1; // ~ (10^10)^(2/3)
const ll PREF_N = MAX_N;

vector <ll> prime;
bool is_composite[MAX_N];
ll phi[MAX_N];
ll prefg[PREF_N];

// phi linear sieve
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

// n^3
ll f(ll n, ll m){
    ll ans = n % m;
    ans *= (ans * ans % m);

    return ans % m;
}

// n^2 phi(n)
ll g(ll n, ll m){
    return (n * n % m) * phi[n] % m;
}

// sum n^3 = (n(n + 1)/2)^2
ll sumf(ll n, ll m){
    ll ans = n;

    if (ans % 2 == 0){
        ans /= 2;
        ans %= m;
        ans *= (n + 1) % m;
        ans %= m;
        ans *= ans;
        
        return ans % m;
    }

    ans %= m;
    ans *= (n + 1)/2 % m;

    ans %= m;
    ans *= ans;

    return ans % m;
}

// sum n^2 = n(n + 1)(2n + 1)/6
ll sums(ll n, ll m){
    ll x = n, y = n + 1, z = 2 * n + 1;
    if (x % 2 == 0){
        x /= 2;
    } else {
        y /= 2;
    }

    if (x % 3 == 0){
        x /= 3;
    } else if (y % 3 == 0){
        y /= 3;
    } else {
        z /= 3;
    }

    return ((x % m) * (y % m) % m) * (z % m) % m;
}

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
                return prefg[i];
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

// sum n^2 phi(n)
// note n^3 = n^2 phi(n) * n^2
FIVector sumg(ll n, ll m){
    FIVector arr(n);


    for (int ii = arr.startIndex; ii < arr.keys.size(); ii++){
        ll key = arr.keys[ii];
        ll ans = 0;

        ll rt = sqrt(key);

        for (ll i = 1; i <= rt; i++){
            if (i != 1){
                ans += m - ((i * i % m) * arr.query(key/i) % m);
                ans %= m;
            }

            ans += m - (g(i, m) * sums(key/i, m) % m);
            ans %= m;
        }

        ans += (sums(rt, m) * prefg[rt] % m);
        ans %= m;

        ans += sumf(key, m);
        ans %= m;

        arr.set(key, ans);
    }

    return arr;
}

ll hyperbola(ll n, ll m){
    ll k = pow((long double)n, 0.5);
    ll l = pow((long double)n, 0.5);

    FIVector computeg = sumg(n, m);

    // cout << k << " " << l << endl;

    ll ans = 0;

    for (ll i = 1; i <= k; i++){
        ll c = f(i, m);
        c *= computeg.query((n/i));
        c %= m;

        ans += c;
        ans %= m;
    }

    for (ll i = 1; i <= l; i++){
        ll c = g(i, m);
        c *= sumf((ll)(n/i), m);
        c %= m;

        ans += c;
        ans %= m;
    }

    ans += m - ((sumf(k, m) * computeg.query(l)) % m);

    return ans % m;
}

void solve(){
    ll n, k; cin >> n >> k;

    sieve(min(n + 1, MAX_N));

    prefg[1] = g(1, k);
    for (ll i = 2; i < min(n + 1, PREF_N); i++){
        prefg[i] = g(i, k) + prefg[i - 1];
        prefg[i] %= k;
    }

    /** 
     * ll ans = 0;

        for (ll i = 1; i <= n; i++){
            ll c = (i * i % k) * (phi[i] % k) % k;
            c *= sumf(n/i, k);
            c %= k;

            ans += c;
            ans %= k;
        }

        cout << ans << endl;
    */

    cout << hyperbola(n, k) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}