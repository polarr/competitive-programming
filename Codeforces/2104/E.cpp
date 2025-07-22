/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-21
 * Contest: 
 * Problem: E
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
    int n, k; cin >> n >> k;

    string s; cin >> s;
    vi arr(n);
    vector<vi> cnt(n + 1, vi(k, 0));
    rep(i, 0, n){
        arr[i] = s[i] - 'a';
        cnt[i + 1] = cnt[i];
        cnt[i + 1][arr[i]]++;
    }

    vi dp(n + 1, 0);
    vi last(k, n);
    for (int i = n - 1; i >= 0; i--){
        int mx = -1;
        rep(j, 0, k){
            mx = max(mx, last[j]);
        }
        dp[i] = 1 + dp[mx];
        last[arr[i]] = i;
    }

    int q; cin >> q;
    rep(i, 0, q){
        string t; cin >> t;
        vi b(t.size());
        rep(j, 0, t.size()){
            b[j] = t[j] - 'a';
        }

        int curr = -1;
        rep(j, 0, t.size()){
            int thing = b[j];
            int lo = curr + 1, hi = n;
            while (lo < hi){
                int mid = (lo + hi)/2;
                if (cnt[mid + 1][thing] - cnt[curr + 1][thing] > 0){
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            curr = lo;
            //cerr << curr << " ";
            if (curr == n) break;
        }

        //cerr << endl;

        cout << dp[curr] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}