/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-04
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
    int n; cin >> n;

    vi clones(n);
    rep(i, 0, n){
        cin >> clones[i];
    }

    vi a = clones;
    sort(all(a));
    reverse(all(a));

    map<int, int> mp;
    int cnt = 0;

    rep(i, 0, n){
        if (i == 0 || a[i] != a[i - 1]){
            mp[a[i]] = cnt++;
        }
    }

    vector<pii> adj(n);

    using T = pii;
    priority_queue<T, vector<T>, greater<T>> pq1, pq2;

    map<int, int> num;

    rep(i, 0, n){
        int k = mp[clones[i]];
        adj[i] = {k, i};
        num[k]++;
        pq1.push(adj[i]);
    }

    vector<bool> visited(n, false);

    int ans = 0;
    int at = 0;
    int visit = 0;

    while (visit < n - 1){
        if (num[at] == 0){
            at++;
            continue;
        }

        while(!pq2.empty() && pq2.top().first < at){
            pq2.pop();
        }

        if (pq2.empty() || at != pq2.top().first){
            pii x = pq1.top();
            pq1.pop();

            if (visited[x.second]){
                continue;
            }

            ans++;
            
            pq2.push(x);
            continue;
        }

        pii x = pq2.top();
        pq2.pop();

        int j = x.second;
        
        if (visited[j]){
            continue;
        }
        
        visited[j] = true;
        visit++;

        num[x.first]--;
        
        if (j > 0 && !visited[j - 1]){
            pq2.push(adj[j - 1]);
        }

        if (j < n - 1 && !visited[j + 1]){
            pq2.push(adj[j + 1]);
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