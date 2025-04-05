/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-01
 * Contest: 
 * Problem: adf2p4
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
    int ans = INT_MAX;
    rep(i, 0, n){
        string s; cin >> s;
        string san = "";
        rep(j, 0, s.size()){
            if (s[j] - '0' < 10){
                san += s[j];
            }
        }

        int a = stoi(san);

        ans = min(a, ans);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}