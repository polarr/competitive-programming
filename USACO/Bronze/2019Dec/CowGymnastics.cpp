/**
 * Solution by 1egend
 * Date:
 * Contest: USACO 
 * Problem:
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "gymnastics";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int k, n;
    fin >> k >> n;
    vector<vector<int>> performances(n, vector<int>(k));
    for (int i = 0; i < k; ++i){
        for (int z = 0; z < n; ++z){
            int t;
            fin >> t;
            performances[t - 1][i] = z;
        }
    }

    int ans = 0;
    for (int a = 0; a < n - 1; ++a){
        for (int b = a + 1; b < n; ++b){
            bool p = true;
            bool q = true;
            for (int i = 0; i < k; ++i){
                if (performances[b][i] < performances[a][i]){
                    p = false;
                }
                if (performances[a][i] < performances[b][i]){
                    q = false;
                }

                if (!p && !q){
                    break;
                }
            }

            if (p || q){
                ++ans;
            }
        }
    }

    fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}