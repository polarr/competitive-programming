/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-11
 * Contest: 2008
 * Problem: D
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

    vector<int> p(n);
    vector<bool> black(n);

    vector<int> g(n, 0);
    vector<int> ans(n + 1, 0);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        p[i] = x - 1;
    }

    string s; cin >> s;

    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            black[i] = false;
        } else {
            black[i] = true;
        }
    }

    int gg = 0;
    for (int i = 0; i < n; i++){
        int curr = i;
        if (g[curr] == 0){
            gg++;
        }

        while (g[curr] == 0){
            g[curr] = gg;
            if (black[curr]){
                ans[gg]++;
            }
            curr = p[curr];
        }
    }

    for (int i = 0; i < n; i++){
        cout << ans[g[i]] << " ";
    }

    cout << endl;
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