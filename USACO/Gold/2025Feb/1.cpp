/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-22
 * Contest: USACO 2025 Feb Gold
 * Problem: 1
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

    vector<vi> children(n);
    vi to(n);
    vl cost(n);
    rep(i, 0, n){
        cin >> to[i];
        --to[i];
        if (to[i] != i) children[to[i]].pb(i);
    }
    //debug_out(children);
    rep(i, 0, n){
        cin >> cost[i];
        if (to[i] == i){
            cost[i] = 0;
        }
    }

    vector<bool> visited(n, false);

    ll ans = 0;

    function<pair<ll, ll>(int, int)> dfs2;
    dfs2 = [&](int node, int avoid){
        ll ans1 = 0;
        ll ans2 = cost[node];

        visited[node] = true;

        for (int x : children[node]){
            if (x == avoid){
                continue;
            }
            pair<ll, ll> a = dfs2(x, avoid);
            ans1 += a.second;
            ans2 += a.first;
        }

        return pair<ll, ll>{min(ans1, ans2), ans2};
    };

    rep(i, 0, n){
        if (to[i] == i){
            ans += dfs2(i, -1).first;
        }
    }

    rep(i, 0, n){
        if (visited[i]){
            continue;
        }

        int curr = i;

        while(!visited[curr]){
            visited[curr] = true;
            curr = to[curr];
        }

        int pr = curr;
        curr = to[curr];
        int nx = to[curr];

        // debug_out(pr, curr, nx);

        // found cycle at curr, p-curr-nx;
        ll ans1 = dfs2(curr, nx).first + dfs2(nx, curr).second;
        ll ans2 = dfs2(pr, curr).first + dfs2(curr, pr).second;
        ans += min(ans1, ans2);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}