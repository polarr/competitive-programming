/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-05
 * Contest: CEOI 2012
 * Problem: race
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

// CORRECT BUT INCOMPLETE, too lazy to finish subtask 2. Basically for each second node, two pointer on the closest first node given the crossing edge and use dp2 to extract. O(n^3).
int n, k;
vector<vector<vi>> dp;
vector<vector<vi>> dp2;
vector<vi> adj;

int idx(int i){
    if (i < 0){
        return n + (i % n);
    }

    return i % n;
}

int rec(int i, int j, int dir){
    if (i == j){
        return 1;
    }

    if (dp[i][j][dir] != 0){
        return dp[i][j][dir];
    }

    int mx = 1;
    if (dir == 1){
        int jj = j < i ? j + n : j;

        for (int k : adj[i]){
            int kk = k < i ? k + n:k;
            if (kk > jj){
                continue;
            }
            mx = max(mx, 1 + rec(idx(kk), idx(i + 1), 0));
            mx = max(mx, 1 + rec(idx(kk), idx(jj), 1));
        }
    } else {
        int ii = i < j ? i + n : i;

        for (int k : adj[i]){
            int kk = k < j ? k + n:k;
            if (kk > ii){
                continue;
            }
            mx = max(mx, 1 + rec(idx(kk), idx(i - 1), 1));
            mx = max(mx, 1 + rec(idx(kk), idx(j), 0));
        }
    }
    

    return dp[i][j][dir] = mx;
}

int rec2(int i, int j, int dir){
    if (i == j){
        return 1;
    }

    if (dp2[i][j][dir] != -1){
        return dp2[i][j][dir];
    }

    int mx = 0;
    if (dir == 1){
        int jj = j < i ? j + n : j;

        for (int k : adj[i]){
            int kk = k < i ? k + n:k;
            if (kk > jj){
                continue;
            }
            int nx = rec2(idx(kk), idx(jj), 1);
            if (nx != 0){
                mx = max(mx, 1 + nx);
            }
        }
    } else {
        int ii = i < j ? i + n : i;

        for (int k : adj[i]){
            int kk = k < j ? k + n:k;
            if (kk > ii){
                continue;
            }
            int nx = rec2(idx(kk), idx(j), 0);
            if (nx != 0){
                mx = max(mx, 1 + nx);
            }
        }
    }

    return dp2[i][j][dir] = mx;
}

void solve(){
    cin >> n >> k;

    adj = vector<vi>(n);

    rep(i, 0, n){
        while (true){
            int x;
            cin >> x;
            if (x == 0){
                break;
            }

            --x;
            adj[i].pb(x);
            // if (k == 0){
            //     adj[i].pb(x);
            // } else {
            //     adj[x].pb(i);
            // }
        }
    }

    dp = vector<vector<vi>>(n, vector<vi>(n, {0, 0}));
    dp2 = vector<vector<vi>>(n, vector<vi>(n, {-1, -1}));

    rep(i, 0, n){
        rep(j, 0, n){
            rep(c, 0, 2){
                rec(i, j, c);
                rec2(i, j, c);
            }
        }
    }

    int ans = 0;
    int ans_i = -1;

    rep(i, 0, n){
        if (dp[i][idx(i - 1)][1] > ans){
            ans = dp[i][idx(i - 1)][1];
            ans_i = i;
        }
    }

    if (k == 0){
        cout << ans - 1 << endl;
        cout << ans_i + 1 << endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}