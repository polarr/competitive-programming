/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-22
 * Contest: USACO 2025 Feb Gold
 * Problem: 2
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

/** TOOL: Debug
 *  PURPOSE: Prints various data types to terminal
 *  SOURCE: tourist
*/
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

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
    int n, m, q; cin >> n >> m >> q;
    vi arr(n, 0);
    set<int> updates;
    vi update(n + 1, 0);
    rep(i, 0, m){
        int l, r; cin >> l >> r;

        update[--l] ^= 1;
        update[r] ^= 1;
    }

    // CompressedBinary cb(n, updates);

    int change = 0;
    rep(i, 0, n){
        if (update[i] == 1){
            change ^= 1;
        }

        if (change){
            arr[i] = 1;
        }
    }

    debug_out(arr);

    vi ones(n + 1, 0);
    vl prefix(n + 1, 0);
    vi search(n + 1, n);
    rep(i, 1, n + 1){
        prefix[i] = prefix[i - 1] * 2 + arr[i - 1];
        prefix[i] %= MOD;

        search[i] = search[i - 1] - 1 + arr[i - 1];
        ones[i] = ones[i - 1] + arr[i - 1];
    }

    debug_out(prefix);
    debug_out(search);
    debug_out(ones);

    reverse(all(search));

    rep(i, 0, q){
        int l, r, k; cin >> l >> r >> k;
        int one_prefix = ones[l - 1];
        int len_suffix = n - r;
        int query = k + one_prefix + len_suffix;

        auto j = lower_bound(search.begin(), search.end(), query);
        int pos = n + 1 - (int)(j - search.begin());
        if (pos == n + 1){
            cout << (mod_exp(2, k, MOD) + MOD - 1) % MOD << endl;
            continue;
        }

        int cnt = ones[pos] - one_prefix;
        if (cnt >= k){
            cout << (mod_exp(2, k, MOD) + MOD - 1) % MOD << endl;
            continue;
        }

        int left = k - cnt;
        //debug_out(query, pos, cnt, left);

        ll ans = mod_exp(2, cnt, MOD) + MOD - 1;
        ans %= MOD;
        ans *= mod_exp(2, left, MOD);
        ans %= MOD;

        ans += prefix[r];
        ans += MOD - (prefix[r - left] * mod_exp(2, left, MOD) % MOD);
        ans %= MOD;

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}