/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-13
 * Contest: 
 * Problem: 4_new
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

const ll INF = 1e17;

void solve(){
    int n, k; cin >> n >> k;
    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    int cnt = 0;
    rep(i, 0, n){
        if (arr[i] == -1){
            cnt++;
        }
    }

    if (cnt >= k - 1){
        cout << "Infinity" << endl;
        return;
    }

    auto check = [&](ll g){
        vl dp(2 * n + 1, -INF);
        int zero = n;
        rep(j, zero + 1, 2 * n + 1){
            dp[j] = INF;
        }

        ll add = 0;
        rep(i, 0, n){
            if (arr[i] == -1) {
                zero--;
                add += g;
            }
            else {
                auto j = upper_bound(all(dp), arr[i] - g - add);
                *j = min(*j, arr[i] - add);
            }
        }

        return dp[zero + k] != INF;
    };

    if (!check(0)){
        cout << -1 << endl;
        return;
    }

    int lo = 0, hi = 1e9;
    while (lo < hi){
        int mid = (lo + hi + 1)/2;
        if (check(mid)){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}