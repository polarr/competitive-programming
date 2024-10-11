/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-11
 * Contest: USACO 2017 Feb Gold
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "nocross";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; fin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++){
        fin >> a[i];
    }

    for (int i = 0; i < n; i++){
        fin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (abs(a[i - 1] - b[j - 1]) <= 4){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    fout << dp[n][n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}