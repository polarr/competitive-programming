/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-15
 * Contest: DMOJ daacc1
 * Problem: 6
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

vector<bool> needed;
vector<vi> adj2;

void dfs(int node){
    if (needed[node]){
        return;
    }

    needed[node] = true;
    for (int x : adj2[node]){
        dfs(x);
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<vi> adj(n);
    adj2 = vector<vi>(n);
    needed = vector<bool>(n, false);
    vector<int> wants(k);
    rep(i, 0, k){
        cin >> wants[i];
        wants[i]--;
    }
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj2[b].pb(a);
    }

    rep(i, 0, k){
        dfs(wants[i]);
    }

    // debug_out(needed);

    vector<int> degree(n, 0);
    queue<pii> q; // use pq for lexicographical sorting
    for (int i = 0; i < n; i++){
        if (!needed[i]){
            continue;
        }
        for (int j : adj[i]){
            degree[j]++;
        }
    }

    for (int i = 0; i < n; i++){
        if (!needed[i]){ continue; }
        if (degree[i] == 0){
            q.push(pii{1, i});
        }
    }

    int mx = 0;
    vi mn(n, 0);
    vector<vi> ans(n + 1);

    while(!q.empty()){
        auto [k, i] = q.front();
        ans[k].pb(i);
        mx = max(mx, k);
        q.pop();

        for (int j : adj[i]){
            if (!needed[j] || degree[j] == 0){
                continue;
            }

            degree[j]--;
            mn[j] = max(mn[j], k);
            if (degree[j] == 0){
                q.push(pii{mn[j] + 1, j});
            }
        }
    }

    cout << mx << endl;
    rep(i, 1, mx + 1){
        sort(all(ans[i]));
        for (int j : ans[i]){
            cout << j + 1 << " ";
        }

        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}