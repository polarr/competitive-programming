/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-13
 * Contest: Codeforces 2067
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
    int n; cin >> n;

    vi x(n);
    vi has(n + 1, 0);
    vi pos(n + 1, -1);
    rep(i, 0, n){
        cin >> x[i];
        pos[x[i]] = i + 1;
        has[x[i]]++;
    }

    rep(i, 1, n + 1){
        if (has[i] == 0){
            // ask this
            int other = n;
            if (i == n){
                other = 1;
            }
            cout << "? " + to_string(i) + " " + to_string(other) << endl;
            int d1; cin >> d1;

            if (d1 == 0){
                cout << "! A" << endl;
                return;
            }

            cout << "! B" << endl;

            return;
        }
    }

    int a = pos[1], b = pos[n];

    cout << "? " + to_string(a) + " " + to_string(b) << endl;

    int d1; cin >> d1;

    cout << "? " + to_string(b) + " " + to_string(a) << endl;

    int d2; cin >> d2;

    if (d1 < n - 1 || d2 < n - 1 || (d1 != d2)){
        cout << "! A" << endl;
        return;
    }

    cout << "! B" << endl;
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