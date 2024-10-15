/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-14
 * Contest: USACO 2020 Jan Gold
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "time";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m, c; fin >> n >> m >> c;
    vector<vector<int>> dp(n, vector<int>(1001, 0));
    vector<vector<int>> adj(n);
    vector<int> money(n);
    //vector<int> d(n, -1);

    for (int i = 0; i < n; i++){
        fin >> money[i];
    }

    for (int i = 0; i < m; i++){
        int a, b; fin >> a >> b;
        --a; --b;
        adj[a].pb(b);
    }

    /**
    queue<int> curr;
    curr.push(0);
    d[0] = 0;
    while(!curr.empty()){
        int n = curr.front();
        curr.pop();

        for (int node: adj[n]){
            if (d[node] != -1){
                continue;
            }
            d[node] = d[n] + 1;
            curr.push(node);
        }
    }
    **/

    for (int i = 1; i < n; i++){
        dp[i][0] = -INT_MAX; 
    }

    for (int t = 1; t < 1001; t++){
        for (int i = 0; i < n; i++){
            int mx = -INT_MAX;
            for (int node: adj[i]){
                int mon = money[node] + dp[node][t - 1];
                if (mon >= 0){
                    mx = max(mx, mon);
                }
            }

            dp[i][t] = mx;
        }
    }

    int ans = 0;

    for (int t = 0; t < 1001; t++){
        ans = max(ans, max(0, dp[0][t]) - c * t * t);
    }

    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}