/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-13
 * Contest: Codeforces 2067
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
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    sort(all(a));

    vi cnt(1001, 0);

    rep(i, 0, n){
        cnt[a[i]]++;
    }

    rep(i, 0, n){
        int x = a[i];
        if (cnt[x] == 1){
            cout << "NO" << endl;
            return;
        }

        rep(j, i + 2, n){
            if (a[j] == x){
                cnt[++a[j]]++;
            }
        }
    }

    cout << "YES" << endl;
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