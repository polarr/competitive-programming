/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-14
 * Contest: IOI 2004
 * Problem: 4 - Phidias
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int w, h; cin >> w >> h;
    int n; cin >> n;

    vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0));

    vector<pair<int, int>> slabs(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        slabs[i] = {a, b};
    }

    for (int i = 1; i < w + 1; i++){
        for (int j = 1; j < h + 1; j++){
            int area = i * j;
            for (int x = 0; x < n; x++){
                pair<int, int> slab = slabs[x];

                if (slab.first > i || slab.second > j){
                    continue;
                }

                area = min(area, min(dp[i - slab.first][slab.second] + dp[i][j - slab.second], dp[slab.first][j - slab.second] + dp[i - slab.first][j]));
            }
            dp[i][j] = area;
        }
    }

    cout << dp[w][h] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}