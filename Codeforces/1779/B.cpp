/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-20
 * Contest: Codeforces 1779
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
    if (n == 3){
        cout << "NO" << endl;
    } else if (n % 2 == 0){
        cout << "YES" << endl;
        rep(i, 0, n){
            if (i % 2 == 0){
                cout << -1 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    } else {
        cout << "YES" << endl;
        int k = (n - 1)/2;
        rep(i, 0, n){
            if (i % 2 == 0){
                cout << k - 1 << " ";
            } else {
                cout << -k << " ";
            }
        }
        cout << endl;
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