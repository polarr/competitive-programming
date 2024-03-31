/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-30
 * Contest: Codeforces Round 1942
 * Problem: C2. Bessie's Birthday Cake (Hard Version)
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
    

    int anchor = 0;

    for (int i = 0; i < x; i++){
        vert[i] -= vert[anchor];
        vert[i] %= n;
    }

    rotate(vert.begin(), vert.begin() + anchor, vert.end());
    **/

    int ans = 0;
    vector<int> diff(x);

    diff[0] = vert[1] - vert[0];

    if (diff[0] == 2){
        ans++;
    }

    diff[x - 1] = n - (vert[x - 1] - vert[0]);
    if (diff[x - 1] == 2){
        ans++;
    }

    for (int i = 1; i < x - 1; i++){
        ans++;
        diff[i] = vert[i + 1] - vert[i];
        
        if (diff[i] == 2){
            ans++;
        }
    }

    // cout << ans;

    vector <int> even;
    vector<int> odd;

    for (int i = 0; i < x; i++){
        if (diff[i] % 2 == 0 && diff[i] > 2){
            even.pb(diff[i]);
        } else if (diff[i] % 2 == 1 && diff[i] > 1){
            odd.pb(diff[i]);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for (int i = 0; i < even.size(); i++){
        if (y < even[i]/2 - 1){
            ans += y * 2;
            y = 0;
        } else {
            ans += even[i] - 1;
            y -= even[i]/2 - 1;
        }

        if (y == 0){
            cout << ans << endl;
            return;
        }
    }

    for (int i = 0; i < odd.size(); i++){
        if (y < floor(odd[i]/2)){
            ans += y * 2;
            y = 0;
        } else {
            ans += odd[i] - 1;
            y -= floor(odd[i]/2);
        }

        if (y == 0){
            cout << ans << endl;
            return;
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