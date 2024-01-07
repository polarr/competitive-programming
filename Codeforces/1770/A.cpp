/**
 * Solution by 1egend
 * Date: 12/30/2022
 * Contest: Good Bye 2022: 2023 is NEAR
 * Problem: A
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;

    vector <int> a, b;
    for (int i = 0; i < n; ++i){
        int t; cin >> t;
        a.pb(t);
    }

    for (int i = 0; i < m; ++i){
        int t; cin >> t;
        b.pb(t);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < m; ++i){
        a[0] = b[i];
        
        int pos = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (a[mid] <= a[0]){
                left = mid + 1;
                pos = mid;
                continue;
            }

            right = mid - 1;
        }

        a.insert(a.begin() + pos + 1, a[0]);
        a.erase(a.begin());
    }

    ull sum = 0;
    for (int i = 0; i < n; ++i){
        sum += a[i];
    }
    
    cout << sum << endl;
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