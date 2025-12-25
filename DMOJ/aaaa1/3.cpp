/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-24
 * Contest: aaaa1
 * Problem: 3
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

void first(){
    int n; cin >> n;
    
    vector<vi> level(n + 1);
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
        level[arr[i]].pb(i);
    }

    vector<bool> live(n, false);

    vi c(n + 1);
    int ans = 0;

    for (int j = n; j >= 1; j--) {
        for (int i : level[j]) {
            ans++;
            live[i] = true;
            if (i != 0 && live[i - 1]) {
                ans--;
            }

            if (i != n - 1 && live[i + 1]) {
                ans--;
            }
        }

        c[j] = ans;
    }

    rep(i, 1, n + 1) {
        cout << c[i] << " ";
    }

    cout << endl;
}

void second(){
    int n; cin >> n;
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    reverse(all(arr));

    vi ans(n, 0);

    int add = 0;
    int rem = 1;
    int remcap = -3;

    int prev = 0;

    rep(i, 0, n) {
        int j = n - i;
        
        int gap = arr[i] - prev;

        while (gap > 0) {
            if (add >= n) {
                cout << -1 << endl;
                return;
            }

            ans[add] = j;
            gap--;
            remcap = add - 1;
            add += 2;
        }

        while (gap < 0) {
            if (rem > remcap) {
                cout << -1 << endl;
                return;
            }

            ans[rem] = j;
            gap++;
            rem += 2;
        }

        prev = arr[i];
    }

    rep(i, 0, n) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    if (t == 1) {
        first();
    } else {
        second();
    }
    return 0;
}