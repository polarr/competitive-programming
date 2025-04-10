/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-10
 * Contest: ICPC Practice Codeforces 597340
 * Problem: A
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
    int c, n; cin >> c >> n;

    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i] += 50;
    }

    int lo = 0;
    int hi = 100;

    while (lo < hi){
        int mid = (lo + hi + 1)/2;

        int cnt = 0;
        bool good = true;

        rep(i, 0, n){
            if (a[i] >= mid){
                cnt = 0;
                continue;
            }

            cnt++;
            if (cnt > c){
                good = false;
                break;
            }
        }

        if (good){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo - 50 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}