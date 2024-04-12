/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-11
 * Contest: CSES Problemset
 * Problem: Introductory - Chessboard and Queens
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<bool>> chessboard(8, vector<bool>(8, true));
int ans = 0;

void generate(unordered_set <int> columns, vector<bool> up, vector<bool> down, int n){
    if (n == 8){
        ans++;
        return;
    }

    for (int x : columns){
        int down_id = x - n + 7;
        int up_id = x + n;  

        if (chessboard[n][x] && up[up_id] && down[down_id]){
            unordered_set<int> temp = columns;
            temp.erase(x);

            vector<bool> next_up = up;
            vector<bool> next_down = down;
            next_up[up_id] = false;
            next_down[down_id] = false;

            generate(temp, next_up, next_down, n + 1);
        }
    }
}

void solve(){
    unordered_set<int> columns = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<bool> up(15, true);
    vector<bool> down(15, true);

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            char x; cin >> x;
            if (x == '*'){
                chessboard[i][j] = false;
            }
        }
    }

    generate(columns, up, down, 0);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}