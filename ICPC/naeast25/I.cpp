#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(a) (int)(a).size()
#define pb push_back

const int INF = 1e6;

void solve(){
    int n; cin >> n;

    int missing = 0;
    vector<vi> p(n);
    rep(i, 0, n){
        rep(j, 0, i + 1){
            int x; cin >> x;
            p[i].pb(x);
            if (x == 100){
                missing++;
            }
        }
    }

    auto checkgood = [&](int i, int j) -> bool {
        int m = i + 1;
        if (i > 0 && j < m - 1) {
            int x = p[i][j];
            int y = p[i][j + 1];
            int z = p[i - 1][j];
            if (x != 100 && y != 100 && z != 100){
                if (x + y != z){
                    return false;
                }
            }
        }

        if (i > 0 && j > 0) {
            int x = p[i][j];
            int y = p[i][j - 1];
            int z = p[i - 1][j - 1];
            if (x != 100 && y != 100 && z != 100){
                if (x + y != z){
                    return false;
                }
            }
        }

        if (i < n - 1) {
            int x = p[i + 1][j];
            int y = p[i + 1][j + 1];
            int z = p[i][j];
            if (x != 100 && y != 100 && z != 100){
                if (x + y != z){
                    return false;
                }
            }
        }

        return true;
    };

    auto findgood = [&](int i, int j) -> int {
        int m = i + 1;
        if (i > 0 && j < m - 1) {
            int x = p[i][j];
            int y = p[i][j + 1];
            int z = p[i - 1][j];
            if (y != 100 && z != 100){
                return z - y;
            }
        }

        if (i > 0 && j > 0) {
            int x = p[i][j];
            int y = p[i][j - 1];
            int z = p[i - 1][j - 1];
            if (y != 100 && z != 100){
                return z - y;
            }
        }

        if (i < n - 1) {
            int x = p[i + 1][j];
            int y = p[i + 1][j + 1];
            int z = p[i][j];
            if (x != 100 && y != 100){
                return x + y;
            }
        }

        return INF;
    };

    while (missing > 0){
        bool changed = false;
        rep(i, 0, n){
            rep(j, 0, i + 1){
                if (p[i][j] == 100){
                    int k = findgood(i, j);

                    if (k == INF){
                        continue;
                    }
                    
                    p[i][j] = k;
                    missing--;
                    changed = true;

                    if (!checkgood(i, j)){
                        cout << "no solution" << endl;
                        return;
                    }

                    if (k < -99 || k > 99){
                        cout << "no solution" << endl;
                        return;
                    }
                }
            }
        }

        if (!changed){
            cout << "ambiguous" << endl;
            return;
        }
    }

    rep(i, 0, n){
        rep(j, 0, i + 1){
            if (!checkgood(i, j)){
                cout << "no solution" << endl;
                return;
            }
        }
    }

    cout << "solvable" << endl;

    rep(i, 0, n){
        rep(j, 0, i + 1){
            cout << p[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}