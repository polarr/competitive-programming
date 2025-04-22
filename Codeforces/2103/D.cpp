/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-21
 * Contest: Codeforces 2103
 * Problem: D
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
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    int l = log2(n);

    int hi = n;
    int lo = 1;

    vi ans(n, -100);

    rep(turn, 1, l + 3){
        if (turn % 2 == 1){
            int stop = n;
            for (int i = n - 1; i >= 0; i--){
                if (ans[i] != -100){
                    continue;
                }

                if (a[i] != turn){
                    stop = i;
                    break;
                }

                ans[i] = hi;
                hi--;
            }

            rep(i, 0, n){
                if (i == stop) break;
                if (a[i] == turn){
                    ans[i] = hi;
                    hi--;
                }
            }
        } else {
            int stop = n;
            for (int i = n - 1; i >= 0; i--){
                if (ans[i] != -100){
                    continue;
                }

                if (a[i] != turn){
                    stop = i;
                    break;
                }

                ans[i] = lo;
                lo++;
            }

            rep(i, 0, n){
                if (i == stop) break;
                if (a[i] == turn){
                    ans[i] = lo;
                    lo++;
                }
            }
        }
    }

    rep(i, 0, n){
        if (a[i] == -1){
            ans[i] = lo;
            lo++;
        }
    }

    for (int a : ans){
        cout << a << " ";
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