/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-21
 * Contest: 
 * Problem: 421
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

const int MAX_N = 1e8 + 1;
const ll MOD = 1e9 + 7;

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

/**
 * PRECOMPUTE: Prime Linear Sieve
 * PURPOSE: Classifies numbers up to MAX_N as primes or not
 * TIME: O(n)
 */
vector<ll> prime;
vector<bool> is_composite(MAX_N + 1, false);
vector<ll> min_div(MAX_N + 1, 1);
void prime_sieve (ll n) {
	for (ll i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.pb(i);
            min_div[i] = i;
		}
		for (ll j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
            min_div[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

ll generator(ll p) {
    vl qs;
    ll r = p - 1;
    while (r != 1) {
        ll q = min_div[r];
        qs.pb(q);
        while (r % q == 0) {
            r /= q;
        }
    }

    rep(cand, 1, p) {
        bool good = true;
        for (ll q : qs) {
            if (mod_exp(cand, (p - 1)/q, p) == 1) {
                good = false;
                break;
            }
        }

        if (good) {
            return cand;
        }
    }
}

ll euclid(ll a, ll b, ll &x, ll &y){
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}
ll inv(ll x, ll m){
    ll ans, _;
    euclid(x, m, ans, _);
    if (ans < 0){
        return (m + (ans % m)) % m;
    }
    return ans % m;
}
ll crt(ll a, ll m, ll b, ll n){
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0){
        return LLONG_MAX;
    }
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x; 
}

void solve(){
    ll n = 1e11;

    using T = array<ll, 2>;

    ll ans = 0;

    for (ll p : prime) {
        ll g = generator(p);
        ll q = p - 1;
        vl good;
        ll period = 1;
        if (q == 1) {
            good = {0};
        } else {
            ll k = 1;
            int a = 0, b = 0;
            while (q % 3 == 0) {
                a++;
                q /= 3;
                k *= 3;
            }

            vector<T> cond3 = {{0, 1}};

            if (a > 0) {
                period *= 3;
                cond3 = {};
                rep(j, 0, 3) {
                    cond3.pb({j * k/3, k});
                }
            }

            k = 1;
            while (q % 5 == 0) {
                b++;
                q /= 5;
                k *= 5;
            }

            vector<T> cond5 = {{0, 1}};
            if (b > 0) {
                period *= 5;
                cond5 = {};
                rep(j, 0, 5) {
                    cond5.pb({j * k/5, k});
                }
            }

            vector<T> condq = {{(inv(15, q) * q/2) % q, q}};

            for (T p3 : cond3) {
                for (T p5 : cond5) {
                    for (T pq : condq) {
                        ll cand = crt(p3[0], p3[1], p5[0], p5[1]);
                        ll p15 = p3[1] * p5[1];
                        cand = crt(cand, p15, pq[0], pq[1]);
                        good.pb(cand);
                    }
                }
            }
        }

        ll m = n / p;
        ll r = n % p;

        ans += p * period * m;
        for (ll cand : good) {
            ll val = mod_exp(g, cand, p);
            if (val <= r) {
                ans += p;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    prime_sieve(MAX_N);
    
    solve();

    return 0;
}