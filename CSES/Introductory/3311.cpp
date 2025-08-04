/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-02
 * Contest: CSES Problemset
 * Problem: 3311
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
    int n, m; cin >> n >> m;
    char a[2] = {'A', 'B'};
    char b[2] = {'C', 'D'};
    rep(i, 0, n){
        string x; cin >> x;
        rep(j, 0, m){
            int take = (i + j) % 2;
            
            if (x[j] == a[take]){
                cout << b[take];
            } else {
                cout << a[take];
            }
        }

        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}