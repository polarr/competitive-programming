/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-21
 * Contest: 
 * Problem: 3419
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

    using T = array<bool, 200>;

    vector<T> row(n), col(n);
    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, 2 * n){
                if (row[i][k] || col[j][k]) continue;
                row[i][k] = true;
                col[j][k] = true;
                cout << k << " ";
                break;
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