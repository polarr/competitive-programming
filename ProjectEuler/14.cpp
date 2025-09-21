/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-21
 * Contest: Project Euler
 * Problem: 14
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

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    vector<bool> visited(MAX_N);
    int mx = 0;
    int ans = 0;
    rep(x, 1, MAX_N){
        if (visited[x]) continue;
        ll curr = x;
        int len = 1;
        while (curr != 1){
            len++;
            if (curr < MAX_N) visited[curr] = true;
            if (curr % 2 == 0) {
                curr /= 2;
            }
            else {
                curr = 3LL * curr + 1;
            }
        }

        if (len > mx){
            mx = len;
            ans = x;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}