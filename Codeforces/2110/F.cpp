/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-24
 * Contest: Codeforces 2110
 * Problem: F
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

// solved in 30 mins!!

void solve(){
    int n; cin >> n;

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    int mx = a[0];
    int smx = 0;
    int ans = 0;

    map<int, bool> taken;
    taken[a[0]] = true;

    cout << ans << endl;

    set<int> possible;

    rep(i, 1, n){
        int x = a[i];
        if (taken[x]){
            cout << ans << " ";
            continue;
        }

        taken[x] = true;
        if (x > mx){
            possible.insert(mx);
            if (x < 2 * mx){
                ans = max(ans, x);
            } else {
                while (!possible.empty()){
                    auto j = possible.begin();
                    if (*j < mx/2){
                        possible.erase(j);
                    } else {
                        break;
                    }
                }

                for (int y : possible){
                    ans = max(ans, y + (x % y));
                }
            }
            
            smx = mx;
            mx = x;
        }
        else if (x >= smx/2){
            smx = max(smx, x);
            ans = max(ans, x + (mx % x));
            possible.insert(x);
        }

        cout << ans << " ";
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