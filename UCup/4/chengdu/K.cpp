#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

template<class Info, class Tag> class LazySegtree {
    public: 
        const int n;
        vector<Info> tree;
        vector<Tag> lazy;

        void build(int v, int l, int r, const vector<Info> &a) {
            if (l == r){
                tree[v] = a[l];
            } else {
                int m = (l + r)/2;
                build(2 * v, l, m, a);
                build(2 * v + 1, m + 1, r, a);
                tree[v] = tree[2 * v] + tree[2 * v + 1];
            }
        }

        void apply(int v, int l, int r, const Tag &x){
            tree[v].apply(x, l, r);
            lazy[v].apply(x);
        }

        void push_down(int v, int l, int r){
            int m = (l + r)/2;
            apply(2 * v, l, m, lazy[v]);
            apply(2 * v + 1, m + 1, r, lazy[v]);
            lazy[v] = Tag();
        }

        void range_update(int v, int l, int r, int ql, int qr, const Tag &x){
            if (qr < l || ql > r) return;
            if (ql <= l && r <= qr) {
                apply(v, l, r, x);
            } else {
                push_down(v, l, r);
                int m = (l + r)/2;
                range_update(2 * v, l, m, ql, qr, x);
                range_update(2 * v + 1, m + 1, r, ql, qr, x);
                tree[v] = tree[2 * v] + tree[2 * v + 1];
            }
        }

        Info range_query(int v, int l, int r, int ql, int qr){
            if (ql < l || ql > r) {
                return Info();
            }
            if (l >= ql && r <= qr){
                return tree[v];
            }

            push_down(v, l, r);
            int m = (l + r)/2;
            return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
        }

        LazySegtree() {}

        LazySegtree(int n) : n(n) {
            tree.assign(4 << __lg(n), Info());
            lazy.assign(4 << __lg(n), Tag());
        }

        LazySegtree(const vector<Info> &a) : n(a.size()) {
            tree.assign(4 << __lg(n), Info());
            lazy.assign(4 << __lg(n), Tag());
            build(1, 0, n - 1, a);
        }

        void range_update(int ql, int qr, const Tag &x){
            range_update(1, 0, n - 1, ql, qr, x);
        }

        Info range_query(int ql, int qr) {
            return range_query(1, 0, n - 1, ql, qr);
        }
};

enum QueryType { ADD, SET, NONE };

struct Tag {
    QueryType type = NONE;
    ll val = 0;

    void apply(const Tag &t){
        if (t.type == ADD){
            val += t.val;
            if (type != SET) {
                type = ADD;
            }
        } else if (t.type == SET){
            type = SET;
            val = t.val;
        }
    }
};

struct InfoMx {
    ll mx = -1e9;
    void apply(const Tag &t, int l, int r){
        if (t.type == SET){
            mx = t.val;
        } else if (t.type == ADD){
            mx += t.val;
        }
    }
};

InfoMx operator+(const InfoMx &a, const InfoMx &b){
    return {max(a.mx, b.mx)};
}

struct InfoSum {
    ll sum = 0;
    void apply(const Tag &t, int l, int r){
        if (t.type == SET){
            sum = t.val * (r - l + 1);
        } else if (t.type == ADD){
            sum += t.val * (r - l + 1);
        }
    }
};

InfoSum operator+(const InfoSum &a, const InfoSum &b){
    return {a.sum + b.sum};
}

void solve() {
    int n, L, k; cin >> n >> L >> k;

    int N = 4 * n;
    LazySegtree<InfoSum, Tag> line(N);
    vector<bool> hasInterval(N, false);

    ll start = 0;

    rep(i, 0, n){
        int l; cin >> l;
        hasInterval[l] = true;
        line.range_update(l, l + L - 1, Tag{ADD, 1});
    }

    vl points(N);

    rep(i, 0, N){
        ll point = line.range_query(i, i).sum;
        points[i] = point;
        if (points[i] == k){
            start++;
        }
    }

    LazySegtree<InfoMx, Tag> st(N);
    st.range_update(0, N - 1, Tag{SET, 0});
    auto add = [&](int i, ll j){
        int lo = max(0, i - L + 1);
        st.range_update(lo, i, Tag{ADD, j});
    };

    rep(i, 0, N){
        if (points[i] == k){
            add(i, -1);
        } else if (points[i] == k - 1){
            add(i, 1);
        }
    }

    // rep(i, 0, N){
    //     cout << st.range_query(i, i).mx << " ";
    // }
    // cout << endl;

    ll ans = start;
    auto put = [&](int j, ll a = 1){
        if (points[j] == k - 1){
            add(j, -1 * a);
        } else if (points[j] == k) {
            add(j, 2 * a);
        } else if (points[j] == k + 1){
            add(j, -1 * a);
        }
    };
    ll curr = start;

    rep(i, 0, N - L + 1){
        if (i == 0){
            rep(j, 0, L){
                if (points[j] == k){
                    curr--;
                }
                if (points[j] == k + 1){
                    curr++;
                }
                put(j, 1);
            }
        } else {
            if (points[i - 1] == k){
                curr++;
            }
            if (points[i - 1] == k + 1){
                curr--;
            }
            if (points[i + L - 1] == k){
                curr--;
            }
            if (points[i + L - 1] == k + 1){
                curr++;
            }
            put(i - 1, -1);
            put(i + L - 1, 1);
        }

        // rep(j, 0, N){
        //     cout << st.range_query(j, j).mx << " ";
        // }
        // cout << endl;
        if (hasInterval[i]) ans = max(ans, curr + st.range_query(0, N - 1).mx);
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
}
