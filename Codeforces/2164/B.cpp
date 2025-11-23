/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-22
 * Contest: Codeforces 2164
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
    int n; cin >> n;
    vi arr(n);
    vi cnt(2, 0);
    rep(i, 0, n) {
        cin >> arr[i];
        cnt[arr[i] % 2]++;
    }

    if (n < 300) {
        rep(i, 0, n) {
            rep(j, i + 1, n) {
                int r = arr[j] % arr[i];
                if (r % 2 == 0) {
                    cout << arr[i] << " " << arr[j] << endl;
                    return;
                }
            }
        }

        cout << -1 << endl;
        return;
    }

    if (cnt[0] >= 2) {
        int a = -1;
        rep(i, 0, n){
            if (arr[i] % 2 == 0) {
                if (a == -1) {
                    a = i;
                } else {
                    cout << arr[a] << " " << arr[i] << endl;
                    return;
                }
            }
        }
        return;
    }

    if (cnt[0] == 1) {
        rep(i, 0, n) {
            if (arr[i] % 2 == 0) {
                arr.erase(arr.begin() + i);
                break;
            }
        }
    }


    rep(i, 0, sz(arr) - 1) {
        if (arr[i + 1] < 2 * arr[i]) {
            cout << arr[i] << " " << arr[i + 1] << endl;
            return;
        }
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