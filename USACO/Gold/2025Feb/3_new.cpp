/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-22
 * Contest: USACO 2025 Feb Gold
 * Problem: 3
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

    vector<vector<bool>> adj(n, vector<bool>(n, true));

    rep(i, 0, n){
        adj[i][i] = false;
    }

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a][b] = false;
        adj[b][a] = false;
    }

    ll ans = 0;

    vector<int> dp(1 << n, 0);

    dp[0] = 0;
    // minimum non-edges to remove so that each node has degree at most 1
    rep(i, 1, 1 << n){
        int ans = INT_MAX;
        for (int p = i; p != 0; p = (p - 1) & i){
            int other = i ^ p;
            int num = 0;
            rep(j, 0, n){
                if ((p & (1 << j)) == 0){
                    continue;
                }

                num++;
            }

            int curr = num * (num - 1)/2;
            rep(j, 0, n){
                if ((i & (1 << j)) == 0){
                    continue;
                }

                bool jp = (p & (1 << j)) != 0;

                rep(k, j + 1, n){
                    if ((i & (1 << k)) == 0){
                        continue;
                    }

                    bool kp = (p & (1 << k)) != 0;

                    if (kp && jp && adj[j][k]){
                        curr--;
                    }

                    if (kp != jp && adj[j][k]){
                        curr++;
                    }
                }
            }

            ans = min(ans, curr + dp[other]);
        }

        dp[i] = ans;
    }

    // debug_out(dp[2]);

    cout << min(m, dp[(1 << n) - 1]) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}