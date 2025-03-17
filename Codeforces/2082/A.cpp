/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-14
 * Contest: Codeforces 2082
 * Problem: A
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

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> grid(n, vi(m));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m){
            grid[i][j] = s[j] - '0';
        }
    }

    int r = 0, c = 0;
    rep(i, 0, n){
        int sum = 0;
        rep(j, 0, m){
            sum += grid[i][j];
        }

        if (sum % 2 == 1){
            r++;
        }
    }

    rep(j, 0, m){
        int sum = 0;
        rep(i, 0, n){
            sum += grid[i][j];
        }

        if (sum % 2 == 1){
            c++;
        }
    }

    cout << max(r, c) << endl;
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