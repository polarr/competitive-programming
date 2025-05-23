/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-22
 * Contest: USACO 2016 Open Platinum
 * Problem: 1
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

const string iofilename = "262144";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; fin >> n;
    vi a(n);
    rep(i, 0, n){
        fin >> a[i];
    }

    vector<vi> can(n, vi(100, -1)), dp(n, vi(100, 0));
    rep(i, 0, n){
        int at = a[i];
        int j = i;
        can[i][at] = 1;
        while(j > 0 && can[j - 1][at] != -1){
            int d = can[j - 1][at];
            j -= d;
            can[i][at + 1] = can[i][at] + d;
            at++;
        }
    }

    rep(k, 0, 100){
        dp[0][k] = max(a[0], k);
        if (a[0] == k) dp[0][k] = k + 1;
    }

    rep(i, 1, n){
        int x = a[i];
        dp[i][0] = max(dp[i - 1][0], x);
        int d = can[i - 1][x];
        if (d == i){
            dp[i][0] = max(dp[i][0], x + 1);
        }
        else if (d != -1){
            dp[i][0] = max(dp[i][0], dp[i - 1 - d][x + 1]);
        }

        rep(k, 1, 99){
            int ans = k;
            ans = max(ans, dp[i][0]);
            int d = can[i][k];
            if (d == i + 1){
                ans = max(ans, k + 1);
            }
            else if (d != -1){
                ans = max(ans, dp[i - d][k + 1]);
            }
            dp[i][k] = ans;
        }
    }

    fout << dp[n - 1][0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}