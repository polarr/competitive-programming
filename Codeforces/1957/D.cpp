/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
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

    vector<int> arr;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr.pb(a);
    }

    vector<int> prefix(n + 1, 0);

    for (int i = 1; i < n + 1; i++){
        prefix[i] = prefix[i - 1] ^ arr[i - 1];
    }

    int ans = 0;
    for (int x = 1; x < n + 1; x++){
        for (int z = x; z < n + 1; z++){
            int range = prefix[z] ^ prefix[x - 1];
            for (int y = x; y < z + 1; y++){
                if ((range ^ arr[y - 1]) > range){
                    // cout << range << arr[y - 1] << " " <<x << y << z << endl;
                    ans++;
                }
            }
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