/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-08
 * Contest: DMOJ bts24 - Back to School '24
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> field(n);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            if (x == 'A'){
                field[i].pb(1);
                continue;
            }

            if (x == 'B'){
                field[i].pb(2);
                continue;
            }

            field[i].pb(0);
        }
    }

    vector<vector<char>> ans(n, vector<char>(m, '.'));

    int block = -1;

    for (int i = 0; i < n; i++){
        block = -1;
        for (int j = 0; j < m; j++){
            if (field[i][j] == 1){
                block = j + k;
                continue;
            }

            if (field[i][j] == 2){
                if (block < j){
                    ans[i][j] = 'Y';
                } else {
                    ans[i][j] = 'N';
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        block = m;
        for (int j = m - 1; j >= 0; j--){
            if (field[i][j] == 2){
                block = j - k;
                continue;
            }

            if (field[i][j] == 1){
                if (block > j){
                    ans[i][j] = 'Y';
                } else {
                    ans[i][j] = 'N';
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j];
        }

        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}