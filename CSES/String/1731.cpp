/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-10
 * Contest: 
 * Problem: 1731
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
 
const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const ll M = (1LL << 61) - 1;
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
 
__int128 mul(ll a, ll b) { return (__int128)a * b; }
ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

vector<ll> pw = {1};

ll FullHash(const string &s) {
    ll curr = 0;
    for (int i = 0; i < s.size(); i++) {
        curr = (mul(curr, B) + s[i]) % M;
    }

    return curr;
}

/**
 * HASH: Rolling Hash
 * COLLISION: With X elements, P <= X^2 N/M
 */
struct HashedString {
	// B^i % M
	vector<ll> p_hash;
 
	HashedString(const string &s) : p_hash(s.size() + 1) {
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}
 
    // 0-indexed, [start, end]
	ll get_hash(int start, int end) {
		ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pw[end - start + 1]);
		return (raw_val + M) % M;
	}
};
 
void solve(){
    string s; cin >> s;
    int n = sz(s);
    HashedString h(s);
 
    int k; cin >> k;
    vector<vl> lens(n);
 
    rep(i, 0, k) {
        string w; cin >> w;
        ll hsh = FullHash(w);
        lens[sz(w) - 1].pb(hsh);
        // has[hsh] = true;
    }

    vl dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        rep(j, 0, n - i) {
            if (lens[j].empty()) continue;
            ll v = h.get_hash(i, i + j);
            for (ll hsh : lens[j]) {
                if (v == hsh) {
                    dp[i] += dp[i + j + 1];
                    dp[i] %= MOD;
                    break;
                }
            }
        }
        // rep(j, i, n) {
        //     ll v = h.get_hash(i, j);
        //     if (!has[v]) continue;
        //     dp[i] += dp[j + 1];
        //     dp[i] %= MOD;
        // }
    }
 
    cout << dp[0] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while (pw.size() < MAX_N) { pw.push_back(mod_mul(pw.back(), B)); }

    solve();
    return 0;
}