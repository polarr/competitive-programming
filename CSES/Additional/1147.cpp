/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-10
 * Contest: DMOJ Problemset - Additional Problems
 * Problem: 1147
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> maxDown(n, vector<int>(m)), maxLeft = maxDown, maxRight = maxDown;

    vector<vector<bool>> forest(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            forest[i][j] = (x == '*');
        }
    }

    for (int j = 0; j < m; j++){
        int k = n;
        for (int i = n - 1; i >= 0; i--){
            if (forest[i][j]){
                k = i;
            }

            maxDown[i][j] = k - i;
        }
    }


    for (int i = 0; i < n; i++){
        stack<pair<int, int>> l, r;

        l.push({-1, -1});
        r.push({m, -1});

        for (int j = 0; j < m; j++){
            while (!l.empty()){
                pair<int, int> t = l.top();
                if (t.second < maxDown[i][j]){
                    maxLeft[i][j] = t.first;
                    break;
                }

                l.pop();
            }

            l.push({j, maxDown[i][j]});
        }

        for (int j = m - 1; j >= 0; j--){
            while (!r.empty()){
                pair<int, int> t = r.top();
                if (t.second < maxDown[i][j]){
                    maxRight[i][j] = t.first;
                    break;
                }

                r.pop();
            }

            r.push({j, maxDown[i][j]});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans = max(ans, maxDown[i][j] * (maxRight[i][j] - maxLeft[i][j] - 1));
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}