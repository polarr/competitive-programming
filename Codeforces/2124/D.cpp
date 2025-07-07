/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-06
 * Contest: 
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
    int n, k; cin >> n >> k;
    --k;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    if (k == 0){
        cout << "YES" << endl;
        return;
    }

    vi brr = arr;
    sort(all(brr));
    int x = brr[k - 1];

    vi segments(1, 0);

    int can = 0;

    vi pal;

    rep(i, 0, n){
        if (arr[i] == x){
            can++;
            segments[segments.size() - 1]++;
        }

        if (arr[i] < x){
            can++;
            pal.pb(arr[i]);
            segments.pb(0);
        }
    }

    bool good = true;

    rep(i, 0, pal.size()/2){
        int j = pal.size() - 1 - i;
        if (pal[i] != pal[j]){
            good = false;
            break;
        }
    }

    if (!good){
        cout << "NO" << endl;
        return;
    }

    can -= k;

    int del = 0;
    rep(i, 0, segments.size()/2){
        int j = segments.size() - 1 - i;
        del += abs(segments[i] - segments[j]);
    }

    // cerr << can << del << endl;

    if (del <= can){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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