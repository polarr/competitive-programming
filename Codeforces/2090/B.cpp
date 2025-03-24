/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-22
 * Contest: Codeforces 2090
 * Problem: B
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

    vector<vi> a(n, vi(m));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m){
            int x = s[j] - '0';
            a[i][j] = x;
        }
    }

    rep(i, 0, n){
        rep(j, 0, m){
            if (a[i][j] == 0){
                continue;
            }

            bool p = true, q = true;
            rep(ii, 0, i){
                if (a[ii][j] == 0){
                    p = false;
                    break;
                }
            }

            rep(jj, 0, j){
                if (a[i][jj] == 0){
                    q = false;
                    break;
                }
            }

            if (!p && !q){
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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