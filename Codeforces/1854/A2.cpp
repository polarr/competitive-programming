/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-21
 * Contest: Codeforces 1854
 * Problem: A2
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
    int pos = 0, neg = 0;
    rep(i, 0, n){
        cin >> a[i];
        if (a[i] < 0){
            neg++;
        } else if (a[i] > 0){
            pos++;
        }
    }

    vector<pii> ans;
    bool found = false;

    if (pos < neg){
        for (int i = n - 1; i >= 0; i--){
            if (!found && a[i] < 0){
                found = true;
                rep(j, i + 2, n){
                    ans.pb({j, j - 1});
                }

                rep(j, 0, 5){
                    ans.pb({i, i});
                }
                continue;
            }

            if (found){
                ans.pb({i, i + 1});
                if (a[i] > 0){
                    ans.pb({i, i + 1});
                }
            }
        }
    } else {
        rep(i, 0, n){
            if (!found && a[i] > 0){
                found = true;
                for (int j = i - 2; j >= 0; j--){
                    ans.pb({j, j + 1});
                }

                rep(j, 0, 5){
                    ans.pb({i, i});
                }
                continue;
            }

            if (found){
                ans.pb({i, i - 1});
                if (a[i] < 0){
                    ans.pb({i, i - 1});
                }
            }
        }
    }

    cout << ans.size() << endl;
    for (pii x : ans){
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }
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