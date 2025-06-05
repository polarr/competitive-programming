/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-22
 * Contest: DMOJ othscc4
 * Problem: 5
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

/** 
 * DATASTRUCTURE: 2D Prefix Sum
 * PURPOSE: Fast queries on a matrix
 * CONSTRAINT: Must input a non-degenerate 2 dimensional matrix
 * TIME: O(nm) to precompute, O(1) to query
*/
template <class T> class Prefix2D {
    private:
        vector<vector<T>> matrix;
    public:
        Prefix2D(vector<vector<T>> &grid){
            matrix = vector<vector<T>>(grid.size() + 1, vector<T>(grid[0].size() + 1, 0));

            for (int i = 0; i < grid.size(); i++){
                for (int j = 0; j < grid[0].size(); j++){
                    matrix[i + 1][j + 1] = grid[i][j] + matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j];
                }
            }
        }

        /**
         * CONSTRAINT: 1 <= y1 <= y2 <= height, 1 <= x1 <= x2 <= width
         * RETURN: sum of submatrix with top-left corner x1, y1 and bottom right corner x2, y2 */
        T query(int x1, int y1, int x2, int y2){
            --x1; --y1;
            return matrix[y2][x2] + matrix[y1][x1] - matrix[y2][x1] - matrix[y1][x2];
        }
};

void solve(){
    int n; cin >> n;
    vector<vi> grid(n, vi(n, 0));
    bool none = true;
    rep(i, 0, n){
        rep(j, 0, n){
            char x; cin >> x;
            if (x == 'x'){
                none = false;
                grid[i][j] = 1;
            }
        }
    }

    if (none){
        cout << 2 * n - 1 << endl;
        return;
    }

    Prefix2D<int> p(grid);

    int ans = 0;

    vector<vi> g(n + 2, vi(n + 2, 0));
    vector<vi> visited1 = g, visited2 = g, d1 = g, d2 = g;
    rep(i, 0, n + 2){
        g[i][0] = 1;
        g[i][n + 1] = 1;
        g[0][i] = 1;
        g[n + 1][i] = 1;
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if (p.query(1, 1, j + 1, i + 1) > 0 && p.query(j + 1, i + 1, n, n) > 0){
                ans++;
                grid[i][j] = 1;
                g[i + 1][j + 1] = 1;
            }
        }
    }

    int mx1 = 0, mx2 = 0;
    function<void(int, int)> floodfill1, floodfill2;
    floodfill1 = [&](int x, int y){
        if (visited1[y][x] == 1){
            return;
        }

        if (g[y][x] == 1){
            if (x > 0 && y > 0 && x < n + 1 && y < n + 1 && grid[y - 1][x - 1] == 1){
                mx1 = max(mx1, d1[y][x]);
            }
            return;
        }

        visited1[y][x] = 1;
        d1[y][x + 1] = d1[y][x] + 1;
        d1[y + 1][x] = d1[y][x] + 1;
        floodfill1(x + 1, y);
        floodfill1(x, y + 1);
    };

    floodfill2 = [&](int x, int y){
        if (visited2[y][x] == 1){
            return;
        }

        if (g[y][x] == 1){
            if (x > 0 && y > 0 && x < n + 1 && y < n + 1 && grid[y - 1][x - 1] == 1){
                mx2 = max(mx2, d2[y][x]);
            }
            return;
        }

        visited2[y][x] = 1;
        d2[y][x - 1] = d2[y][x] + 1;
        d2[y - 1][x] = d2[y][x] + 1;
        floodfill2(x - 1, y);
        floodfill2(x, y - 1);
    };

    floodfill1(1, 1);
    floodfill2(n, n);

    cout << mx1 + mx2 + ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}