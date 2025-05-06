/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-05
 * Contest: 
 * Problem: F1
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

    vl a(n + 1, 1e18);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<vl> dp(n + 1, vl(n + 1, 1e18));
    vl mn(n + 1, LLONG_MAX);
    vl smn(n + 1, LLONG_MAX);
    vi mnj(n + 1, -1);
    

    rep(i, 0, n + 1){
        dp[0][i] = 0;
        mn[0] = min(mn[0], a[i] + i);
    }

    rep(i, 1, n + 1){
        rep(j, 0, n + 1){
            if (j != i - 1) {
                dp[i][j] = min(dp[i - 1][i - 1] + a[i - 1], dp[i - 1][j] + a[j] + 1);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[j] + 1);
            }

            dp[i][j] = min(dp[i][j], mn[i - 1]);

            // if (mnj[i - 1] != j) {
            //     dp[i][j] = min(dp[i][j], mn[i - 1]);
            // } else {
            //     dp[i][j] = min(dp[i][j], smn[i - 1]);
            // }

            ll can = dp[i][j] + a[j] + (ll) abs(j - i);

            if (j != i - 1) mn[i] = min(mn[i], can);

            debug_out(i, j, mn[i]);


            // if (can < mn[i]){
            //     smn[i] = mn[i];
            //     mn[i] = can;
            //     mnj[i] = j;
            // } else {
            //     smn[i] = min(smn[i], can);
            // }
        }
    }
    
    debug_out(dp);
    debug_out(mn);

    cout << dp[n][n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}