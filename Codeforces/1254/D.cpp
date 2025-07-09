/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-06
 * Contest: 
 * Problem: D
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

const int MAX_N = 150000;
const ll MOD = 998244353;


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


int n, q; 

vector<vi> adj;
vl ans;
vector<vi> sizes;
vi subtr;
vector<pii> pos;
vector<vi> tour;

int k = 0;
void dfs(int x, int par){
    pos[x].first = k++;
    for (int node : adj[x]){
        if (node == par) continue;
        
        dfs(node, x);
        tour[x].pb(k++);
        sizes[x].pb(subtr[node]);
        subtr[x] += subtr[node];
    }
    
    pos[x].second = k - 1;
}

vector<pii> op;

ll invn;
ll total = 0;

vl contrib;

// debug_out(tour[0]);

ll query (int x){
    ll a = ans[x] + total;
    a %= MOD;
    // debug_out(x);
    for (auto &[v, d] : op){
        if (x == v) continue;

        ll siz = n - subtr[v];
        if (pos[x].first >= pos[v].first && pos[x].first <= pos[v].second){
            int j = upper_bound(all(tour[v]), pos[x].first) - tour[v].begin();
            siz = sizes[v][j];
        }
        
        // debug_out(x, v, siz, pos[x], sizes[v]);

        a += MOD - siz * invn % MOD * (ll) d % MOD;
        a %= MOD;
    }

    return a;
}

void dfs2(int x, int par, ll curr){
    curr %= MOD;
    curr += (ll)(n - subtr[x]) * invn % MOD * contrib[x] % MOD;
    curr %= MOD;

    ans[x] += total;
    ans[x] %= MOD;
    ans[x] += curr;
    ans[x] %= MOD;

    int sub = 0;

    rep(i, 0, adj[x].size()){
        int node = adj[x][i];
        if (node == par) {
            sub = 1;
            continue;
        }
        dfs2(node, x, curr + MOD - (ll) sizes[x][i - sub] * invn % MOD * contrib[x] % MOD);
    }
}

// should work asymptotically but TL so tight :(

void solve(){
    cin >> n >> q;
    
    adj = vector<vi>(n);
    ans = vl(n, 0);
    sizes = vector<vi>(n);
    subtr = vi(n, 1);
    pos = vector<pii>(n);
    tour = vector<vi>(n);

    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    invn = mod_exp(n, MOD - 2, MOD);
    contrib = vl(n, 0);

    dfs(0, -1);
    int rt = sqrt(n);

    int added = 0;

    rep(i, 0, q){
        if (added == rt){
            for (auto &[v, d] : op){
                total += MOD - (ll)(n - subtr[v]) * invn % MOD * (ll)d % MOD;
                total %= MOD;
            }
            dfs2(0, -1, 0);
            total = 0;
            for (auto &[v, d] : op){
                contrib[v] = 0;
            }
            op = {};
            added = 0;
        }

        int c;
        cin >> c;
        if (c == 1){
            added++;
            int v; ll d; cin >> v >> d;
            --v;

            total += d;
            total %= MOD;
            op.pb({v, d});
            contrib[v] += d;
            contrib[v] %= MOD;
        } else {
            int v; cin >> v;
            --v;
            cout << query(v) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}