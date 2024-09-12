/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-12
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define uull unsigned long long
#define ull long long

const int MAX_N = 1e5 + 1;
const ull MOD = 1e9 + 7;

vector<vector<ull>> mat{{1, 1}, {1, 0}};

vector<vector<ull>> mat_sq(vector<vector<ull>> const &a){
    return vector<vector<ull>>{{
            (a[0][0] * a[0][0] + a[0][1] * a[1][0]) % MOD, (a[0][0] * a[0][1] + a[0][1] * a[1][1]) % MOD
        }, {
            (a[1][0] * a[0][0] + a[1][1] * a[1][0]) % MOD, (a[1][0] * a[0][1] + a[1][1] * a[1][1]) % MOD
        }
    };
}

vector<vector<ull>> mat_1(vector<vector<ull>> const &b){
    return vector<vector<ull>>{{
            (b[0][0] + b[1][0]) % MOD, (b[0][1] + b[1][1]) % MOD
        }, {
            (b[0][0]) % MOD, (b[0][1]) % MOD
        }
    };
}

vector<vector<ull>> mat_pow(int r){
    if (r == 1){
        return mat;
    }

    vector<vector<ull>> rr = mat_pow(r/2);

    if (r % 2 == 1){
        return mat_1(mat_sq(rr));
    } else {
        return mat_sq(rr);
    }
}

void solve(){
    ull n; cin >> n;

    // characteristic 
    // 6 -4
    // 1 0

    vector<ull> a = mat_pow(n - 1)[0];
    int ans = (1 * a[0] + MOD) % MOD;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}