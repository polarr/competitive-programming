/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-24
 * Contest: Codeforces 2043
 * Problem: E
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

bool check(vector<vector<bool>>& A, vector<vector<bool>>& B, vector<int>& is, vector<int>& js, vector<int>& rs, vector<int>& cs){
    int n = is.size(), m = js.size();

    for (int k = 0; k < n; k++){
        if (rs[k] == 0){
            if (n == 1){
                return true;
            }

            is.erase(is.begin() + k);
            rs.erase(rs.begin() + k);

            return check(A, B, is, js, rs, cs);
        }
    }

    for (int k = 0; k < m; k++){
        if (cs[k] == n){
            if (m == 1){
                return true;
            }

            js.erase(js.begin() + k);
            for (int i = 0; i < n; i++){
                rs[i]--;
            }
            cs.erase(cs.begin() + k);

            return check(A, B, is, js, rs, cs);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int ii = is[i], jj = js[j];
            if (A[ii][jj] != B[ii][jj]){
                return false;
            }
        }
    }

    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B = A;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> B[i][j];
        }
    }

    // check by bit
    for (int k = 0; k < 30; k++){
        vector<vector<bool>> Ak(n, vector<bool>(m));
        vector<vector<bool>> Bk = Ak;

        vector<int> rs(n, 0);
        vector<int> cs(m, 0);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                Ak[i][j] = (A[i][j] & (1 << k));
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                Bk[i][j] = (B[i][j] & (1 << k));
                rs[i] += (int)Bk[i][j];
                cs[j] += (int)Bk[i][j];
            }
        }

        vector<int> is(n);
        vector<int> js(m);
        for (int i = 0; i < n; i++){
            is[i] = i;
        }
        for (int i = 0; i < m; i++){
            js[i] = i;
        }

        if (!check(Ak, Bk, is, js, rs, cs)){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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