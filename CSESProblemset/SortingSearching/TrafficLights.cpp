/**
 * Solution by 1egend
 * Date: 7/5/2021
 * Contest: CSES Problemset - Sorting and Searching
 * Problem: Traffic Lights 1163
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int x, n;
    cin >> x >> n;
    set<int> lights {0, x};
    int ans = 1;
    for (int i = 0; i < n; ++i){
        static int t;
        cin >> t;
        if (*lights.upper_bound(t) - *(--lights.upper_bound(t)) >= ans){
            lights.insert(t);
            int a = 1;
            if (t == *lights.begin() + 1){
                lights.erase(lights.begin());
            }
            for (auto i = lights.begin(); i != lights.end(); ++i){
                a = max<int>(a, *next(i) - *i);
            }
            ans = a;
        }
        else {
            lights.insert(t);
        }
        cout << ans << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}	