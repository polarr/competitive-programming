/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-05
 * Contest: ICPC NAQ 2024
 * Problem: G
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<vector<int>> gears(MAX_N);

    for (int i = 0; i < n; i++){
        int s, c; cin >> s >> c;
        gears[s].pb(c);
    }

    double ans = 0;
    for (int i = 1; i < MAX_N; i++){
        if (gears[i].size() == 0){
            continue;
        }

        sort(gears[i].begin(), gears[i].end());

        int nn = gears[i].size();

        for (int j = 0; j < nn/2; j++){
            ans += log((double)(gears[i][nn - 1 - j])) - log((double)(gears[i][j]));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}