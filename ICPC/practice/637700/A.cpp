/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-24
 * Contest: 
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
    int n, m; cin >> n >> m;
    vector<pair<string, int>> arr(n);
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m){
            if (j % 2 == 1){
                s[j] = 'A' + ('Z' - s[j]);
            }
        }

        arr[i] = {s, i};
    }

    sort(all(arr));
    rep(i, 0, n){
        cout << arr[i].second + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}