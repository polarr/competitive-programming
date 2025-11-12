#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define sz(a) (int)(a).size()
#define pb push_back

const int INF = 1e6;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n) {
        n = _n;
        bit = vector<ll>(n + 1, 0);
    }
    void add(int x, ll v) {
        while (x <= n) {
            bit[x] += v;
            x += x & -x;
        }
    }
    ll getSum(int x) {
        ll sum = 0;
        while (x > 0) {
            sum += bit[x];
            x -= x & -x;
        }
        return sum;
    }
    ll getSum(int l, int r) {
        if (l > r) {
            return 0;
        }
        return getSum(r) - getSum(l - 1);
    }
};

void solve(){
    ll mx, my; cin >> mx >> my;

    Fenwick st(4 * INF), st2(4 * INF), st3(4 * INF), st4(4 * INF), st5(4 * INF);

    auto len = [&](ll tot, ll d1, ll d2){
        ll hi = tot - max(0LL, max(d1, d2));
        ll lo = max(0LL, -min(d1, d2));

        return max(0LL, hi - lo + 1);
    };

    rep(dx, -mx, mx + 1){
        rep(dx2, -mx, mx + 1){
            ll prod = dx * dx2;
            ll l = len(mx, dx, dx2);

            st.add(INF + prod, l);

            if (dx == dx2){
                st2.add(INF + prod, l);
            }

            if (dx == 0){
                st3.add(INF + prod, l);
            }

            if (dx2 == 0){
                st4.add(INF + prod, l);
            }

            if (dx == 0 && dx2 == 0){
                st5.add(INF + prod, l);
            }
        }
    }

    ll points = (my + 1) * (mx + 1);
    ll total = (points * (points - 1) * (points - 2)) / 6;

    ll od = 0, r = 0;

    rep(dy, -my, my + 1){
        rep(dy2, -my, my + 1){
            ll prod = dy * dy2;
            ll l = len(my, dy, dy2);

            // dy prod smaller than dx
            ll lesser = st.getSum(1, INF - prod - 1);
            od += l * lesser;

            r += l * st.getSum(INF - prod, INF - prod);

            if (dy == dy2){
                od -= l * st2.getSum(1, INF - prod - 1);
            }

            if (dy == 0){
                r -= l * st3.getSum(INF - prod, INF - prod);
            }

            if (dy2 == 0){
                r -= l * st4.getSum(INF - prod, INF - prod);
            }

            if (dy == 0 && dy2 == 0){
                r += l * st5.getSum(INF - prod, INF - prod);
            } else if (dy == dy2){
                r -= l * st2.getSum(INF - prod, INF - prod);
            }
        }
    }

    od /= 2;
    r /= 2;

    ll a = total - r - od;
    ll d = 0;
    rep(dy, -my, my + 1){
        rep(dy2, -my, my + 1){
            if (dy == dy2) continue;
            if (dy == 0) continue;
            if (dy2 == 0) continue;
            rep(dx, -mx, mx + 1) {
                if (dx == 0) continue;
                if (dx * dy2 % dy == 0) {
                    ll dx2 = dx * dy2 / dy;
                    d += len(mx, dx, dx2) * len(my, dy, dy2);                       
                }
            }
        }
    }

    d /= 6;

    d += ((my + 1) * (mx + 1) * (mx) * (mx - 1)) /6;
    d += ((mx + 1) * (my + 1) * (my) * (my - 1)) /6;

    ll o = od - d;
    cout << a << endl;
    cout << r << endl;
    cout << o << endl;
    cout << d << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}