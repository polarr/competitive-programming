/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-30
 * Contest: Codeforces 1976 - Educational Codeforces Round 166 (Rated for Div. 2)
 * Problem: C
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
    vector<ll> a;
    vector<ll> b;
    for (int i = 0; i < n + m + 1; i++){
        ll aa; cin >> aa;
        a.pb(aa);
    }

    for (int i = 0; i < n + m + 1; i++){
        ll aa; cin >> aa;
        b.pb(aa);
    }

    ll skill = 0;
    int programmers = 0;
    int testers = 0;
    int last = -1;
    int last_type = (m == 0 ? 1:0);
    int last_trade = 0;

    for (int i = 0; i < n + m; i++){
        if (programmers == n){
            skill += b[i];
            if (a[i] > b[i] && last_trade == 0){
                last_trade = a[i] - b[i];
            }
            continue;
        }

        if (testers == m){
            skill += a[i];
            if (b[i] > a[i] && last_trade == 0){
                last_trade = b[i] - a[i];
            }
            continue;
        }

        if (a[i] > b[i]){
            skill += a[i];
            programmers++;
            if (programmers == n && last == -1){
                last = i;
            }
        } else {
            skill += b[i];
            testers++;
            if (testers == m && last == -1){
                last = i;
                last_type = 1;
            }
        }
    }

    for (int i = 0; i < n + m + 1; i++){
        if (i > last || (b[i] > a[i] && last_type == 0) || (a[i] > b[i] && last_type == 1)){
            if (last_type == 0){
                cout << (skill - b[i] + b[n + m]) << " ";
            } else {
                cout << (skill - a[i] + a[n + m]) << " ";
            }
            continue;
        }

        if (last_type == 0){
            if (last_trade == 0){
                cout << (skill - a[i] + a[n + m]) << " ";
            } else {
                cout << (skill - a[i] + last_trade + b[n + m]) << " ";
            }
        } else {
            if (last_trade == 0){
                cout << (skill - b[i] + b[n + m]) << " ";
            } else {
                cout << (skill - b[i] + last_trade + a[n + m]) << " ";
            }
        }
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