/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-03
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
    int n, z; cin >> n >> z;
    vi times(n + 1, INT_MAX);
    rep(i, 0, n){
        int x; cin >> times[i];
    }

    int lg = log2(n) + 1;
    vector<vi> jp(n + 1, vi(lg, n));
    vector<vector<pii>> jmp(n + 1, vector<pii>(lg, {n, 0}));

    int idx = n;
    for (int i = n - 1; i >= 0; i--){
        while (times[i] + z < times[idx]){
            idx--;
        }

        jp[i][0] = idx + 1;
    }

    rep(j, 1, lg){
        rep(i, 0, n){
            int k = jp[i][j - 1];
            jp[i][j] = jp[k][j - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--){
        if (times[i] + z < times[i + 1]){
            jmp[i][0] = {i + 1, 1};
            continue;
        }

        int a = i, b = i + 1;
        int mn1 = 0, mn2 = 0;
        pii ans1, ans2;
        for (int k = lg - 1; k >= 0; k--){
            if (jp[a][k] != jp[b][k]){
                a = jp[a][k];
                b = jp[b][k];
                mn1 += (1 << k);
            }
        }

        mn1++;
        ans1 = {jp[a][0], 2 * mn1};
        a = jp[i][0], b = i + 1;
        for (int k = lg - 1; k >= 0; k--){
            if (jp[a][k] != jp[b][k]){
                a = jp[a][k];
                b = jp[b][k];
                mn2 += (1 << k);
            }
        }

        mn2++;
        ans2 = {jp[a][0], 2 * mn2 + 1};
        if (ans2.second < ans1.second){
            jmp[i][0] = ans2;
        } else {
            jmp[i][0] = ans1;
        }
    }

    // rep(i, 0, n){
    //     debug_out(jmp[i][0]);
    // }

    rep(j, 1, lg){
        rep(i, 0, n){
            pii a = jmp[i][j - 1];
            pii b = jmp[a.first][j - 1];
            jmp[i][j] = {b.first, a.second + b.second};
        }
    }

    int q; cin >> q;
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = 0;
        int a = l;
        for (int j = lg - 1; j >= 0; j--){
            if (jmp[a][j].first <= r){
                ans += jmp[a][j].second;
                a = jmp[a][j].first;
            }
        }

        if (a == r){
            ans++;
        } else {
            int b = a + 1;
            ans += 2;
            for (int j = lg - 1; j >= 0; j--){
                if (jp[a][j] <= r){
                    ans += (1 << j);
                    a = jp[a][j];
                }

                if (jp[b][j] <= r){
                    ans += (1 << j);
                    b = jp[b][j];
                }
            }
        }

        cout << ans << endl;
    }
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