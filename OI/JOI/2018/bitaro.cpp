/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-10
 * Contest: JOI 2018
 * Problem: bitaro
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
    int n, m, q; cin >> n >> m >> q;

    vector<vi> children(n);
    vi parcount(n, 0);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        children[b].pb(a);
        parcount[a]++;
    }

    int rt = sqrt(n);
    vector<vector<pii>> longest(n);
    vector<bool> visited(n, false);
    vector<bool> has(n, false);
    function<void(int)> dfs;
    dfs = [&](int x){
        if (visited[x]) return;
        visited[x] = true;
        for (int node : children[x]){
            dfs(node);
        }

        int mm = children[x].size();
        vi at(mm, 0);
        int added = 0;
        vi did;
        while (added < rt){
            int mx = -100;
            int mxi = -1;
            int mxx = -1;
            rep(i, 0, mm){
                int node = children[x][i];
                if (at[i] == longest[node].size()) continue;

                auto [l, xx] = longest[node][at[i]];
                if (has[xx]){
                    at[i]++;
                    --i;
                    continue;
                }

                if (l > mx){
                    mx = l;
                    mxi = i;
                    mxx = xx;
                }
            }

            if (mx == -100) break;

            longest[x].pb({mx + 1, mxx});
            has[mxx] = true;
            did.pb(mxx);
            at[mxi]++;
            added++;
        }

        for (int node : did){
            has[node] = false;
        }

        if (added < rt){
            longest[x].pb({0, x});
        }
    };

    rep(i, 0, n){
        if (parcount[i] != 0) continue;
        dfs(i);
    }


    vi cache(n);
    function<int(int, vector<bool>&)> query;
    query = [&](int x, vector<bool>& cannot){
        if (visited[x]){
            return cache[x];
        }

        visited[x] = true;
        int ans = -1;
        for (int node : children[x]){
            int mx = query(node, cannot);
            if (mx == -1) continue;
            ans = max(ans, 1 + mx);
        }
        if (!cannot[x]){
            ans = max(ans, 0);
        }

        cache[x] = ans;
        return ans;
    };

    vector<bool> cannot(n, false);

    rep(i, 0, q){
        int a, y; cin >> a >> y;
        --a;
        
        vi cant;
        rep(j, 0, y){
            int x; cin >> x;
            --x;
            cannot[x] = true;
            cant.pb(x);
        }

        int ans = -1;

        if (y < rt){
            rep(j, 0, longest[a].size()){
                auto [l, x] = longest[a][j];
                if (cannot[x]) continue;

                ans = l;
                break;
            }
        } else {
            cache = vi(n);
            visited = vector<bool>(n, false);
            ans = query(a, cannot);
        }

        for (int x : cant){
            cannot[x] = false;
        }

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}