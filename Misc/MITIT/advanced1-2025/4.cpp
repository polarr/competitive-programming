/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-19
 * Contest: MITIT advanced1-2025
 * Problem: 4
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
    vector<array<int, 3>> points;
    for (int i = 0; i < n; i++){
        int x, y; string s; cin >> x >> y >> s;

        if (s == "UD"){
            points.pb({x, y, 0});
        } else {
            points.pb({x, y, 1});
        }
    }

    sort(points.begin(), points.end());

    int ans = 0;

    for (int i = 0; i < pow(2, n); i++){
        vector<int> dir(n);
        for (int j = 0; j < n; j++){
            bool toggled = i & (1 << j);
            if (points[j][2] == 0){
                dir[j] = (int) toggled;
            } else {
                dir[j] = 2 + (int) toggled;
            }
        }

        bool valid = true;
        for (int a = 0; a < n; a++){
            for (int b = 0; b < n; b++){
                if (a == b){
                    continue;
                }
                array<int, 3> pta = points[a], ptb = points[b];
                if (pta[0] < ptb[0] && pta[1] < ptb[1]){
                    if (dir[a] == 1 && dir[b] == 2){
                        valid = false;
                    }

                    if (dir[a] == 3 && dir[b] == 0){
                        valid = false;
                    }
                }
                if (pta[0] < ptb[0] && pta[1] > ptb[1]){
                    if (dir[a] == 3 && dir[b] == 1){
                        valid = false;
                    }

                    if (dir[a] == 0 && dir[b] == 2){
                        valid = false;
                    }
                }
            }
        }
        if (valid){
            ans++;
            ans %= MOD;
        }
    }

    if (ans > 0){
        cout << "YES" << endl;
        cout << ans << endl;
        return;
    }

    cout << "NO" << endl;
    cout << 0 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}