/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-10
 * Contest: Codeforces 2078
 * Problem: D
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

    vector<pair<pair<ll, ll>, pair<ll, ll>>> gates(n);
    rep(i, 0, n){
        char c; ll x; cin >> c >> x;
        if (c == '+'){
            gates[i].first = {0, x};
        } else {
            gates[i].first = {1, x};
        }

        cin >> c >> x;
        if (c == '+'){
            gates[i].second = {0, x};
        } else {
            gates[i].second = {1, x};
        }
    }

    auto contrib = [&](int i, int j){
        pair<ll, ll> gate = gates[i].first;
        if (j == 1){
            gate = gates[i].second;
        }

        if (gate.first == 0){
            return 0LL;
        }

        return gate.second - 1;
    };

    //debug_out(gates);

    vector<pair<ll, ll>> dp(n + 1);

    dp[n] = {1, 1};
    dp[n - 1] = {1 + contrib(n - 1, 0), 1 + contrib(n - 1, 1)};

    for (int i = n - 2; i >= 0; i--){
        ll a = 1, b = 1;
        rep (j, i, n){
            a += contrib(j, 0) * max(dp[j + 1].first, dp[j + 1].second);
            b += contrib(j, 1) * max(dp[j + 1].first, dp[j + 1].second);
        }
        dp[i].first = a;
        dp[i].second = b;
    }

    debug_out(dp);

    ll ans = dp[0].first + dp[0].second;
    rep(i, 0, n){
        ll give = max(dp[i + 1].first, dp[i + 1].second);
        if (gates[i].first.first == 0){
            ans += gates[i].first.second * give;
        }

        if (gates[i].second.first == 0){
            ans += gates[i].second.second * give;
        }
    }

    cout << ans << endl;
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