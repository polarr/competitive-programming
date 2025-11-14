/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-13
 * Contest: 
 * Problem: C
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
    int n; cin >> n;
    vi arr(n);
    int e = 0, o = 0;
    rep(i, 0, n){
        int x; cin >> x;
        if (x % 2 == 0){
            e++;
        } else {
            o++;
        }

        arr[i] = x;
    }

    if (e == 0 || o == 0){
        rep(i, 0, n){
            cout << arr[i] << " ";
        }

        cout << endl;
        return;
    } else {
        sort(all(arr));
    }
    
    rep(i, 0, n){
        cout << arr[i] << " ";
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