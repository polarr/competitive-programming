/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-07
 * Contest: CSES Problemset
 * Problem: 2181
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
    
    vector<vl> dp(1 << n, vl(m + 1, 0));

    rep(i, 0, 1 << n){
        int cnt = 0;
        bool can = true;
        rep(j, 0, n){
            bool c = i & (1 << j);
            if (!c){
                if (cnt % 2 == 1){
                    can = false;
                    break;
                }
                cnt = 0;
            } else {
                cnt++;
            }
        }

        if (cnt % 2 == 1){
            can = false;
        }

        dp[i][1] = (ll)can;
    }

    vector<vl> possible(1 << n);

    possible[0] = {(1 << n) - 1};

    auto pre = [&](int j){
        return (1 << n) - (1 << j); 
    };

    rep(i, 1, 1 << n){
        vl ans = {};
        
        for (int j = n - 1; j >= 0; j--){
            bool c = i & (1 << j);
            if (!c){
                continue;
            }
            int add = pre(j + 1);
            bool d = false;
            if (j > 0){
                d = i & (1 << (j - 1));
            }

            if (!d){
                for (int msk : possible[i ^ (1 << j)]){
                    ans.pb(msk ^ (1 << j));
                }
            } else {
                for (int msk : possible[i ^ (1 << j)]){
                    ans.pb(msk ^ (1 << j));
                }

                for (int msk : possible[i ^ (1 << j) ^ (1 << (j - 1))]){
                    ans.pb(msk);
                }
            }

            break;
        }

        possible[i] = ans;
    }

    // debug_out(possible[(1 << n) - 1]);

    rep(j, 2, m + 1){
        rep(i, 0, 1 << n){
            ll ans = 0;
            for (int msk : possible[i]){
                ans += dp[msk][j - 1];
                ans %= MOD;
            }

            dp[i][j] = ans;
        }
    }

    cout << dp[(1 << n) - 1][m] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}