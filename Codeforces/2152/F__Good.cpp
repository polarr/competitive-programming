/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-07
 * Contest: 
 * Problem: F_brute
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
    int n, z; cin >> n >> z;
    vi times(n + 1, INT_MAX);
    rep(i, 0, n){
        int x; cin >> times[i];
    }

    int q; cin >> q;
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        --l; --r;

        int a = l, b = l;
        int ans = 0;
        while (a <= r && b <= r){
            ans++;
            if (a == b){
                b++;
                continue;
            }

            rep(i, a + 1, n + 1){
                if (times[i] > times[a] + z){
                    if (b == i){
                        ans--;
                    }
                    a = b;
                    b = i;
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}