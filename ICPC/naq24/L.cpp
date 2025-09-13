/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-13
 * Contest: ICPC NAQ 2024
 * Problem: L
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

vector<pii> cardinal = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(){
    int r, c; cin >> r >> c;
    vector<vi> grid(r, vi(c, 0)), visited = grid;

    queue<pii> active, nx;
    vector<pii> path;

    pii apple;
    int len = 0;

    rep(i, 0, r){
        string s; cin >> s;
        rep(j, 0, c){
            char x = s[j];
            if (x == '.'){
                grid[i][j] = 0;
            }
            else if (x == 'A'){
                apple = {i, j};
                grid[i][j] = -1;
            } else if ('0' <= x && x <= '9') {
                len++;
                grid[i][j] = 1 + (x - '0');
                if (x == '0') {
                    nx.push({i, j});
                    path.pb({i, j});
                }
            } else {
                len++;
                grid[i][j] = 11 + (x - 'a');
            }
        }
    }

    while (!nx.empty()){
        active = nx;
        nx = {};
        while (!active.empty()){
            pii curr = active.front();
            active.pop();

            if (grid[curr.first][curr.second] == -1){
                cout << 1 << endl;
                return;
            }
            visited[curr.first][curr.second] = 1;
            for (pii dir : cardinal){
                pii adj = curr;
                adj.first += dir.first;
                adj.second += dir.second;
                if (adj.first < 0 || adj.first >= r || adj.second < 0 || adj.second >= c){
                    continue;
                }

                if (visited[adj.first][adj.second]) continue;
                if (grid[adj.first][adj.second] > 0) continue;

                nx.push(adj);
            }
        }
    }

    int ans = 0;

    function<void(int)> dfs;
    dfs = [&](int depth){
        if (depth > 15){
            return;
        }

        pii curr = path[sz(path) - 1];
        for (pii dir : cardinal){
            pii adj = curr;
            adj.first += dir.first;
            adj.second += dir.second;
            if (adj.first < 0 || adj.first >= r || adj.second < 0 || adj.second >= c){
                continue;
            }

            bool flag = false;
            rep(i, 0, sz(path)){
                pii& pr = path[sz(path) - 1 - i];
                if (adj.first == pr.first && adj.second == pr.second){
                    flag = true;
                    break;
                }
            }

            if (flag) continue;

            if (grid[adj.first][adj.second] > 0){
                if (grid[adj.first][adj.second] > len - depth + (len == 2)){
                    ans = 1;
                    return;
                }
                continue;
            }

            if (adj.first == apple.first && adj.second == apple.second) {
                ans = 1;
                return;
            }

            path.pb(adj);
            dfs(depth + 1);
            path.pop_back();
        }
    };

    dfs(1);

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}