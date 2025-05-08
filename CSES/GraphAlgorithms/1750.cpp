/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-08
 * Contest: CSES Problemset
 * Problem: 1750
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

// TL very tight on this one, can't even use vector
int jump[MAX_N][30];

void solve(){
    int n, q; cin >> n >> q;

    int lg = 30;
    rep(i, 0, n){
        cin >> jump[i][0];
        --jump[i][0];
    }

    rep(i, 1, lg){
        rep(j, 0, n){
            int k = jump[j][i - 1];
            jump[j][i] = jump[k][i - 1];
        }
    }

    rep(i, 0, q){
        int x, k; cin >> x >> k;
        --x;

        int ans = x;
        for (int j = lg - 1; j >= 0; j--){
            if (k & (1 << j)){
                ans = jump[ans][j];
            }
        }

        cout << ans + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}