/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-21
 * Contest: USACO 2025 Feb Silver
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
    int n; cin >> n;

    vector<vi> children(n + 1);
    vector<set<int>> responsible(n + 1);
    vi cnt(n + 1, 0);
    rep(i, 0, n){
        int par; cin >> par;
        children[par].pb(i + 1);
    }

    int leafCount = 0;
    function<void(int,pair<int, int>,int)> dfs;
    vector<pii> dp(n + 1);

    dfs = [&](int node, pii x, int depth){
        dp[node] = x;

        if (children[node].size() == 0){
            responsible[x.second].insert(node);
            leafCount++;
            return;
        }

        pii nx = x;

        if (children[node].size() > 1){
            if (node != 0) responsible[x.second].insert(node);
            nx = {depth, node};
        }

        for (int child : children[node]){
            dfs(child, nx, depth + 1);
        }
    };


    dfs(0, {-1, 0}, 0);


    rep(i, 0, n + 1){
        cnt[i] = responsible[i].size();
    }

    //debug_out(responsible);

    function<void(int)> propagate;

    propagate = [&](int node){
        if (node == 0){
            return;
        }
        int crit = dp[node].second;
        cnt[crit]--;
        responsible[crit].erase(node);
        if (cnt[crit] == 1){
            int j = *(responsible[crit].begin());
            int ccrit = dp[crit].second;
            if (ccrit != -1){
                responsible[dp[crit].second].erase(crit);
                responsible[dp[crit].second].insert(j);
            }
            dp[j] = dp[crit];
        }
        if (cnt[crit] == 0){
            //debug_out(crit);
            propagate(crit);
        }
    };

    rep(i, 0, leafCount){
        int node; cin >> node;
        cout << dp[node].first + 1 << endl;
        propagate(node);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}