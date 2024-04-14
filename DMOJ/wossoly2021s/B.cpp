/**
 * Solution by 1egend
 * Date:
 * Contest: WOSS 
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

const string iofilename = "";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; cin >> n;
    vector<vector<int>> lights(4);
    for (int i = 0; i < 4; ++i){
        for (int ii = 0; ii < n; ++ii){
            char t;
            cin >> t;
            int a;
            if (t == 'R'){
                a = 1;
            } else if (t == 'G'){
                a = 2;
            } else {
                a = 3;
            }
            lights[i].pb(a);
        }
    }

    // A B C 1 2 3 
    vector<int> row(10, 0);
    vector<int> col(10, 0);
    for (int i = 0; i < n; ++i){
        int rowp = lights[0][i] * lights[2][i];
        int colp = lights[3][i] * lights[1][i];

        ++row[rowp];
        ++col[colp];
    }

    ull ans = 0;
    for (int r = 0; r < 10; ++r){
        ull k = row[r];
        if (r == 1){
            k *= col[6];
        } else if (r == 4){
            k *= col[3];
        } else if (r == 9){
            k *= col[2];
        } else if (r == 6){
            k *= (col[1] + col[2] + col[3]);
        } else if (r == 2){
            k *= (col[3] + col[6] + col[9]);
        } else if (r == 3){
            k *= (col[2] + col[4] + col[6]);
        }

        ans += k;
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}