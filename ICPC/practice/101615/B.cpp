/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-09
 * Contest: ICPC Practice Codeforces 101615
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    /** NOTE: incomplete */
    int n, x; cin >> n >> x;

    vector<int> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i];
    }

    ll ans = 0;
    do {
        int mx = points[p[n - 1]];
        int mn = 0;
        for (int i = 0; i < n; i++){
            int t = max(mn, mx + 1 - points[p[i]]);

            mx++;
        }

    } while(next_permuatation(p.b));

    cout << ans << endl;
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