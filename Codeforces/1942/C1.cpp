/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-30
 * Contest: Codeforces Round 1942
 * Problem: C1. Bessie's Birthday Cake (Easy Version)
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    assert(y == 0);

    vector<int> vert;
    for (int i = 0; i < x; i++){
        int v;
        cin >> v;
        v--; // 0 to n - 1
        vert.pb(v);
    }

    sort(vert.begin(), vert.end());

    /**
    int neighbor_min = 3;
    int anchor = 0;
    for (int i = 0; i < x; i++){
        int neighbor = 0;
        if (abs(vert[(i + 1) % x] - vert[i]) % (n - 1) <= 1){
            neighbor++;
        }
        if (abs(vert[(i - 1) % x] - vert[i]) % (n - 1) <= 1){
            neighbor++;
        }

        if (neighbor < neighbor_min){
            neighbor_min = neighbor;
            anchor = i;

            if (neighbor_min == 0){
                break;
            }
        }
    }

    for (int i = 0; i < x; i++){
        vert[i] -= vert[anchor];
        vert[i] %= n;
    }

    rotate(vert.begin(), vert.begin() + anchor, vert.end());
    **/

    int ans = 0;

    if (vert[1] - vert[0] == 2){
        ans++;
    }

    if (vert[x - 1] - vert[0] == n - 2){
        ans++;
    }

    for (int i = 1; i < x - 1; i++){
        ans++;

        if (vert[i + 1] - vert[i] == 2){
            ans++;
        }
    }

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