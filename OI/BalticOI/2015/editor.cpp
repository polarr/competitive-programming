/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-26
 * Contest: Baltic OI 2015
 * Problem: editor
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

    vi a(n);
    vi level(n, 0);
    rep(i, 0, n){
        cin >> a[i];
    }
    
    int lg = log2(n) + 1;
    vector<vi> jump(n, vi(lg, -1));

    auto query = [&](int i, int x){
        if (i < 0){
            return -1;
        }

        if (level[i] <= x){
            return i;
        }

        for (int k = lg - 1; k >= 0; k--){
            int j = jump[i][k];
            if (j == -1 || level[j] <= x) continue;

            i = j;
        }

        return jump[i][0];
    };

    rep(i, 0, n){
        if (a[i] < 0){
            int x = -a[i];
            level[i] = x;
            int j = query(i - 1, x - 1);

            jump[i][0] = query(j - 1, x - 1);
            rep(k, 1, lg){
                if (jump[i][k - 1] == -1) break;
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }

        int j = query(i, 0);

        cout << (j == -1 ? 0 : a[j]) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}