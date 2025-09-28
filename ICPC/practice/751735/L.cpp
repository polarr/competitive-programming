/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-27
 * Contest: VJudge 751735
 * Problem: L
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

    int rt = sqrt(n);
    vector<vi> sums(rt);
    rep(i, 1, rt){
        sums[i] = vi(i, 0);
    }

    string s; cin >> s;
    vi arr(n);
    rep(i, 0, n){
        arr[i] = s[i] - '0';
        arr[i] = 1 - arr[i];

    }
    rep(i, 0, n){
        if (arr[i] == 1){
            rep(j, 1, rt){
                sums[j][i % j]++;
            }
        }
    }

    int q; cin >> q;

    rep(i, 0, q){
        int t; cin >> t;
        int k; cin >> k;
        --k;
        if (t == 1){
            arr[k] = 0;
            rep(j, 1, rt){
                sums[j][k % j]--;
            }
        } else if (t == 2){
            arr[k] = 1;
            rep(j, 1, rt){
                sums[j][k % j]++;
            }
        } else {
            int x; cin >> x;
            int ans = 0;
            if (x >= rt){
                for (int j = k; j < n; j += x){
                    ans += arr[j];
                }

                cout << ans << endl;
            } else {
                cout << sums[x][k % x] << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}