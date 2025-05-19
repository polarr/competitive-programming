/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-17
 * Contest: Codeforces 2109
 * Problem: C2
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

bool bad = false;

void solve(){
    int n; cin >> n;
    
    int res;
    cout << "mul " << 9 << endl;
    cin >> res;

    cout << "digit" << endl;
    cin >> res;

    cout << "digit" << endl;
    cin >> res;
    
    if (n != 9){
        cout << "add " << n - 9 << endl;
        cin >> res;
    }

    cout << "!" << endl;
    cin >> res;

    if (res == -1){
        bad = true;
        return;
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
        if (bad) break;
    }
    return 0;
}