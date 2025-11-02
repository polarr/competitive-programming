#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

const ll INF = 1e17;

template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i, 0, N) {
            rep(j, 0, N) {
                a.d[i][j] = -INF;
                rep(k, 0, N){
                    a.d[i][j] = max(a.d[i][j], d[i][k] + m.d[k][j]);
                }
            }
        }
        return a;

    }
    array<T, N> operator * (const array<T, N> &vec) const {
        array<T, N> ret{};
        rep(i, 0, N){
            ret[i] = -INF;
            rep(j, 0, N){
                ret[i] = max(ret[i], d[i][j] + vec[j]);
            }
        }

        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i, 0, N) {
            rep(j, 0, N){
                a.d[i][j] = -INF;
            }
            a.d[i][i] = 0;
        }

        while(p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }

        return a;
    }
};

const int max_pw = (1 << 6);

void solve() {
    int n, m, k, R; cin >> n >> m >> k >> R;

    // cout << n << m << k << R << endl;
    vl damage(n), cost(n);
    rep(i, 0, n){
        cin >> damage[i];
        cin >> cost[i];
    }

    int pw = (1 << n);

    Matrix<ll, max_pw> mat;
    rep(i, 0, max_pw){
        rep(j, 0, max_pw){
            mat.d[i][j] = -INF;
        }
    }

    rep(i, 0, pw){
        rep(j, 0, pw){
            ll tot_cost = 0;
            ll tot_damage = 0;
            rep(t, 0, n){
                bool row = i & (1 << t);
                bool col = j & (1 << t);
                if (row) {
                    tot_damage += damage[t];
                    tot_cost += cost[t];
                    if (col){
                        tot_cost += k;
                    }
                }
            }

            if (tot_cost <= m){
                mat.d[i][j] = tot_damage;
            }
        }
    }

    R--;
    array<ll, max_pw> arr;
    rep(i, 0, max_pw){
        arr[i] = -INF;
    }
    rep(i, 0, pw){
        ll tot_cost = 0;
        ll tot_damage = 0;
        rep(t, 0, n){
            bool row = i & (1 << t);
            if (row) {
                tot_damage += damage[t];
                tot_cost += cost[t];
            }
        }

        if (tot_cost <= m){
            arr[i] = tot_damage;
        }
    }

    mat = mat ^ R;
    arr = mat * arr;
    ll ans = 0;
    rep(i, 0, pw){
        ans = max(ans, arr[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
