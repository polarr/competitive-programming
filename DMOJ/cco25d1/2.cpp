/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-05
 * Contest: CCO 2025 Day 1
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

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    map<vi, int> iso;
    int k = 0;
    vi key(n);
    vector<vi> keyChild(n);
    vi total(n, 0);
    vl subtr(n);
    vl subtr2(n);

    function<void(int, int)> dfs;
    dfs = [&](int x, int par){
        ll st = 1;
        ll ste = 0;
        vi children;
        for (int node : adj[x]){
            if (node == par) continue;

            dfs(node, x);
            children.pb(key[node]);
            st += subtr2[key[node]];
            ste += subtr[key[node]];
        }

        sort(all(children));
        if (iso.contains(children)){
            key[x] = iso[children];
        } else {
            keyChild[k] = children;
            iso[children] = k;
            key[x] = k;
            subtr[k] = st + ste;
            subtr2[k] = st;
            k++;
        }

        total[key[x]]++;
    };

    dfs(0, -1);

    int ans = 0;

    function<void(int, ll, vl&)> dfs2;
    dfs2 = [&](int x, ll depth, vl& need){
        need[x] += depth;

        for (int node : keyChild[x]){
            dfs2(node, depth + 1, need);
        }
    };

    rep(i, 0, k){
        if (subtr[i] != n - m){
            continue;
        }

        vl need(k, 0);
        dfs2(i, 1, need);

        bool good = true;
        rep(j, 0, k){
            if (need[j] > total[j]){
                good = false;
                break;
            }
        }

        if (good) ans++;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}