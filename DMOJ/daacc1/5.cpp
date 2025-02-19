/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-15
 * Contest: DMOJ daacc1
 * Problem: 5
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
    string s; cin >> s;
    string t; cin >> t;
    vi count(4); cin >> count[0] >> count[1] >> count[2] >> count[3];
    vi arr(4, 0);

    int ans = 0;
    int mx = 0;
    int left = n;
    rep(i, 0, n){
        int x = s[i] - 'A';
        int y = t[i] == '?' ? -1:t[i]-'A';

        if (y != -1){
            if (x == y){
                ans++;
            }

            count[y]--;
            left--;
            continue;
        }

        arr[x]++;
    }

    rep(i, 0, 4){
        if (arr[i] + count[i] > left){
            mx = max(mx, arr[i] + count[i] - left);
        }
    }

    cout << ans + mx << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}