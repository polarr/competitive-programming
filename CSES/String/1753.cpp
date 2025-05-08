/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-07
 * Contest: CSES Problemset
 * Problem: 1753
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

/**
 * HASH: Rolling Hash
 * COLLISION: With X elements, P <= X^2 N/M
 */
class HashedString {
  private:
	static const ll M = (1LL << 61) - 1;
	static const ll B;

	// B^i % M
	static vector<ll> pow;

	vector<ll> p_hash;

	__int128 mul(ll a, ll b) { return (__int128)a * b; }
	ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	ll get_hash(int start, int end) {
		ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);


void solve(){
    string haystack, needle; cin >> haystack >> needle;

    int m = needle.size();

    HashedString a(haystack), b(needle);

    int ans = 0;
    rep(i, m - 1, haystack.size()){
        if (a.get_hash(i - m + 1, i) == b.get_hash(0, m - 1)){
            ans++;
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