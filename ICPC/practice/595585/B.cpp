/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-12
 * Contest: Codeforces ICPC Practice 595585
 * Problem: B
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;

    multiset<int> d;
    rep(i, 0, n){
        int a; cin >> a;
        d.insert(a);
    }
    
    int ad = 0;
    int ans = 0;
    int x = 0;


    while(d.size() > 1){        
        if (ad == 0){
            x = *(d.begin());
            d.erase(d.begin());
            if (x >= k){
                ans++;
                ad = 0;
                continue;
            }

            ad++;
        }
        else if (ad == 1){
            auto y = d.upper_bound(k - 1 - x);
            if (y == d.begin()){
                ans++;
                ad = 0;
                d.erase(prev(d.end()));
                continue;
            } else {
                d.erase(prev(y));
            }
            ad++;
        } else {
            d.erase(prev(d.end()));
            ans++;
            ad = 0;
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