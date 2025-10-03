/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-02
 * Contest: Codeforces 2029
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

void solve(){
    int n; cin >> n;
    int rr = 0, bb = 0;
    vi arr(n);
    string c; cin >> c;
    rep(i, 0, n){
        if (c[i] == 'R'){
            arr[i] = 0;
        } else {
            arr[i] = 1;
        }
    }

    rep(i, 0, n){
        int nx = (i + 1) % n;
        if (arr[i] == 0 && arr[nx] == 0){
            rr++;
        }
        if (arr[i] == 1 && arr[nx] == 1){
            bb++;
        }
    }

    if (rr > 0 && bb > 0){
        cout << "NO" << endl;
        return;
    }

    if (bb > 0){
        rep(i, 0, n){
            arr[i] = 1 - arr[i];
        }
    }

    int b = 0;
    rep(i, 0, n){
        if (arr[i] == 1){
            b++;
        }
    }

    if (b <= 1){
        cout << "YES" << endl;
        return;
    }

    int curr = 0;
    int s = -1;
    int cnt = 0;
    rep(i, 0, n){
        if (arr[i] == 1){
            if (s == -1){
                s = curr;
            }
            else if (curr % 2 == 0){
                cnt++;
            }
            curr = 0;
        } else{
            curr++;
        }
    }

    curr += s;
    if (curr % 2 == 0){
        cnt++;
    }

    if (cnt != 1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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