/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-05
 * Contest: 
 * Problem: C
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
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    vector<array<ll, 3>> x;

    x.pb({0, 0, 0});

    vl a(n);

    rep(i, 0, n){
        cin >> a[i];
    }

    int last = 0;

    bool can = false;

    rep(i, 1, n + 1){
        if (i == n || s[i] != s[i - 1]){
            if (s[i - 1] == '1'){
                ll mx = 0;
                ll mxx = 0;
                ll pref = 0, suff = 0;
                rep(j, last, i){
                    mx += a[j];
                    mxx += a[j];
                    if (mxx < 0) mxx = 0;
                    // if (mx < 0) mx = 0;

                    if (mxx > k){
                        cout << "No" << endl;
                        return;
                    }

                    pref = max(mx, pref);
                }

                mx = 0;

                for (int j = i - 1; j >= last; j--){
                    mx += a[j];
                    // if (mx < 0) mx = 0;

                    suff = max(mx, suff);
                }

                x.pb({pref, suff, last});
            } else {
                can = true;
                x.pb({-1, i - last, last});
            }

            last = i;
        }
    }

    if (!can){
        ll mx = 0;
        ll ans = 0;
        rep(i, 0, n){
            mx += a[i];
            if (mx < 0) mx = 0;

            ans = max(mx, ans);
        }

        if (ans == k){
            cout << "Yes" << endl;
            rep(i, 0, n){
                cout << a[i] << " ";
            }

            cout << endl;
        } else {
            cout << "No" << endl;
        }

        return;
    }

    x.pb({0, 0, 0});

    debug_out(x);

    cout << "Yes" << endl;

    bool found = false;

    vl ans = a;

    rep(i, 0, x.size()){
        array<ll, 3> p = x[i];

        if (p[0] != -1){
            continue;
        }

        if (found){
            rep(j, p[2], p[2] + p[1]){
                ans[j] = -1e18;
            }
            continue;
        }

        found = true;

        if (p[1] == 1){
            ans[p[2]] = (ll) k - x[i - 1][1] - x[i + 1][0];
        } else {
            ans[p[2]] = (ll) k - x[i - 1][1];
            rep(j, p[2] + 1, p[2] + p[1]){
                ans[j]  = -1e18;
            }
        }
    }

    rep(i, 0, n){
        cout << ans[i] << " ";
    }

    cout << endl;
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