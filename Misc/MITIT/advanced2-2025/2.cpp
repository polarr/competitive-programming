#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int M = 3e3+5, MOD = 1e9+7;
int A[M][M], X[M][M], Y[M][M], Z[M][M];



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

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            X[i][j] = (A[i][j] == A[i-1][j]) && (A[i][j] == A[i][j-1]) && (A[i][j] == A[i-1][j-1]);
            if (i > 1) Y[i][j] = (A[i][j] == A[i-1][j]) && (A[i][j] == A[i-2][j]);
            if (j > 1) Z[i][j] = (A[i][j] == A[i][j-1]) && (A[i][j] == A[i][j-2]);
        }
    }

    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            X[i][j] += X[i-1][j] + X[i][j-1] - X[i-1][j-1];
            Y[i][j] += Y[i-1][j] + Y[i][j-1] - Y[i-1][j-1];
            Z[i][j] += Z[i-1][j] + Z[i][j-1] - Z[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << X[i][j] << ' '; cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << Y[i][j] << ' '; cout << endl;
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b, x, y;
        cin >> b >> a >> y >> x;
        x++; y++;

        a++; b++;
        bool b1 = (b < y && a < x) && (X[x][y] + X[a][b] - X[x][b] - X[a][y] > 0);
        a--; b++;
        bool b2 = b < y && (Y[x][y] + Y[a][b] - Y[x][b] - Y[a][y] > 0);
                debug_out(Y[x][y], Y[a][b], Y[x][b], Y[a][y]);
        a+= 2; b-= 2;
        bool b3 = a < x && (Z[x][y] + Z[a][b] - Z[x][b] - Z[a][y] > 0);
        cout << b2 << endl;
        cout << ((b1 || b2 || b3) ? "NO":"YES") << endl;
    }

    return 0;
}