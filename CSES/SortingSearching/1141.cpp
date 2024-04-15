/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 1141. Sorting and Searching - Playlist
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

map<int, int> last;

void solve(){
    int n; cin >> n;

    int ans = 0;
    int d = -1;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        if (last.count(k) > 0){
            d = max(d, last[k]);
        }
        ans = max(ans, i - d);
        last[k] = i;
    }

    cout << max(ans, n - d - 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}