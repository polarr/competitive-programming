/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-14
 * Contest: USACO 2016 December Platinum
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ull MOD = 1e9 + 9;

const string iofilename = "team";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, m, k; fin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    for (int j = 0; j < m; j++){
        fin >> b[j];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> prevSmaller(n, -1);

    int curr = 0;

    for (int i = 0; i < n; i++){
        if (i > 0){
            prevSmaller[i] = prevSmaller[i - 1];
        }
        while(a[i] > b[curr] && curr < m){
            prevSmaller[i] = curr;
            curr++;
        }
    }

    vector<vector<vector<ull>>> dp(n + 1, vector<vector<ull>>(m + 1, vector<ull>(k + 1, 0)));
    vector<vector<vector<ull>>> sumdp(n + 1, vector<vector<ull>>(m + 1, vector<ull>(k + 1, 0)));

     for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            int small = prevSmaller[i - 1];
            if (small == -1){
                continue;
            }
            dp[i][j][1] = (dp[i - 1][j][1] + min(small + 1, j));
            dp[i][j][1] %= MOD;

            sumdp[i][j][1] = sumdp[i][j - 1][1] + dp[i][j][1];
            sumdp[i][j][1] %= MOD;
        }
    }

    for (int x = 2; x < k + 1; x++){
        for (int i = 1; i < n + 1; i++){
            if (i < x){
                continue;
            }
            int small = prevSmaller[i - 1];
            if (small == -1){
                continue;
            }
            for (int j = 1; j < m + 1; j++){
                if (j < x){
                    continue;
                }
                dp[i][j][x] = (dp[i - 1][j][x] + sumdp[i - 1][min(small + 1, j) - 1][x - 1]);
                dp[i][j][x] %= MOD;

                sumdp[i][j][x] = sumdp[i][j - 1][x] + dp[i][j][x];
                sumdp[i][j][x] %= MOD;
            }
        }
    }

    fout << dp[n][m][k] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}