/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-14
 * Contest: Baltic OI 2016
 * Problem: swap
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

const int MAX_N = 2e5 + 1;
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

// O(n logn) space
vector<vector<pii>> dp;
vi tree;
int nn = 1;

int findpos(int a, int val){
    return (*prev(upper_bound(all(dp[a]), pii{val, INT_MAX}))).second;
}

/** THIS DOES NOT WORK SINCE THE "end up" position of a value in a subtree root is not monotonic 
 * But easy fix, just ditch the binary sort and DP directly, only logn values of subtree roots possible, and you only need to compare end up positions to determine optimal allocation (very trivial)
*/

// T(n) = 2T(n/2) + O(n + logn)
// O(n logn) by master theorem
void rec(int node){    
    if (node >= nn/2){
        // leaf
        dp[node] = {{1, node}};
        return;
    }

    int a = 2 * node, b = 2 * node + 1;
    int aa = tree[a], bb = tree[b];
    rec(a); rec(b);

    dp[node].pb({1, node});
    if (aa < bb){
        bool found = false;
        rep(i, 0, dp[a].size()){
            pii el = dp[a][i];

            if (!found && (i == dp[a].size() - 1 || dp[a][i + 1].first > aa + 1)){
                found = true;
                dp[node].pb({aa + 1, el.second});
                continue;
            }

            if (found){
                dp[node].pb(el);

            }
        }

        return;
    }

    int p1 = findpos(a, aa);
    int p2 = findpos(b, aa);
    bool found = false;
    rep(i, 0, dp[a].size()){
        pii el = dp[a][i];

        if (el.first >= aa){
            break;
        }

        if (el.second >= p2){
            int crit = el.first;
            bool found = false;
            rep(j, 0, dp[b].size()){
                pii ell = dp[b][j];

                if (ell.first >= aa){
                    break;
                }

                if (!found && (i == dp[b].size() - 1 || dp[b][j + 1].first > crit)){
                    found = true;
                    dp[node].pb({crit, el.second});
                    continue;
                }

                if (found){
                    dp[node].pb(ell);
                }
            }
            break;
        }

        if (!found && (i == dp[a].size() - 1 || dp[a][i + 1].first > bb + 1)){
            found = true;
            dp[node].pb({bb + 1, el.second});
            continue;
        }

        if (found){
            dp[node].pb(el);
        }
    }

    vector<pii> add1, add2;

    int crit = INT_MAX;
    found = false;
    rep(i, 0, dp[b].size()){
        pii el = dp[b][i];

        if (!found && el.second >= p1 && (i == dp[b].size() - 1 || dp[b][i + 1].first > aa + 1)){
            crit = i;
            found = true;
            add1.pb({aa + 1, el.second});
            continue;
        }

        if (found){
            add1.pb(el);
        }
    }

    rep(i, 0, add2.size()){
        dp[node].pb(add2[i]);
    }

    rep(i, 0, add1.size()){
        dp[node].pb(add1[i]);
    }
}

void extract(int node){
    if (node >= nn/2){
        return;
    }

    int x = tree[node];
    int a = 2 * node, b = 2 * node + 1;
    int aa = tree[a], bb = tree[b];

    if (x < aa && x < bb){
        extract(a); extract(b);
        return;
    }

    if (aa < bb){
        swap(tree[node], tree[a]);
        extract(a); extract(b);
        return;
    }

    tree[node] = bb;

    if (x > aa){
        swap(x, aa);
    }

    int p1 = findpos(a, x);
    int p2 = findpos(b, aa);
    if (p1 < p2){
        tree[a] = x;
        tree[b] = aa;
    } else {
        tree[a] = aa;
        tree[b] = x;
    }

    extract(a); extract(b);
}

void solve(){
    int n; cin >> n;
    while(nn <= n){
        nn *= 2;
    }

    tree = vi(nn, MAX_N);
    dp = vector<vector<pii>>(nn);

    rep(i, 0, n){
        cin >> tree[i + 1];
    }

    rec(1);

    rep(i, 1, nn){
        // debug_out(dp[i]);
    }

    extract(1);

    rep(i, 1, n + 1){
        cout << tree[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}