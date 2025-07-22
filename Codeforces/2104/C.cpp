/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-21
 * Contest: 
 * Problem: C
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

    vi own(n);
    string s; cin >> s;
    int a = 0, b = 0;
    rep(i, 0, n){
        own[i] = s[i] - 'A';
        if (own[i] == 0){
            a++;
        } else {
            b++;
        }
    }

    if (own[0] == 0 && own[n - 1] == 0){
        cout << "Alice" << endl;
        return;
    }

    if (own[0] == 1 && own[n - 1] == 1){
        cout << "Bob" << endl;
        return;
    }

    if (own[n - 1] == 1){
        if (b == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
        return;
    }

    if (n == 2){
        cout << "Bob" << endl;
        return;
    }

    if (own[n - 2] == 0){
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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