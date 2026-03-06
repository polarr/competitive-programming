/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-05
 * Contest: 
 * Problem: F
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

void solve(){
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vi pre(n + 1, 0);
    rep(i, 0, n) {
        pre[i + 1] = pre[i] ^ arr[i];
    }

    ll wsum = 0, lsum = 0;
    map<int, ll> w, l;

    lsum++;
    l[pre[n]]++;

    ll evensum = 0, oddsum = 0;

    vl dpw(n + 1, 0), dpl(n + 1, 1);

    for (int i = n - 1; i >= 0; i--) {
        ll at = pre[i];

        if (arr[i] != 1) {
            evensum = 0;
            oddsum = 0;
        } else {
            swap(evensum, oddsum);
        }

        ll lll = l[at];
        ll wl = lsum + MOD - l[at];
        ll ww = wsum + MOD + MOD - w[at] - oddsum + evensum;
        ll lw = wsum + MOD - ww;

        ll lose = lll + lw;
        ll win = wl + ww;
        lose %= MOD;
        win %= MOD;

        evensum += win;
        evensum %= MOD;

        dpl[i] = lose;
        dpw[i] = win;

        w[at] += win;
        w[at] %= MOD;

        l[at] += lose;
        l[at] %= MOD;

        lsum += lose;
        lsum %= MOD;

        wsum += win;
        wsum %= MOD;
    }

    cout << dpw[0] << endl;
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