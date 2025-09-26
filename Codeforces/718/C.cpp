/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: Codeforces 718
 * Problem: C
**/

#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

/** 
 * DATASTRUCTURE: Matrix
 * PURPOSE: Common matrix template
 * TIME: O(nmp) for n x m times m x p matrix; supports binary exponentiation
 * SOURCE: USACO Guide
*/
template <typename T> void matmul(vector<vector<T>> &a, vector<vector<T>> b) {
	int n = a.size(), m = a[0].size(), p = b[0].size();
	assert(m == b.size());
	vector<vector<T>> c(n, vector<T>(p));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	a = c;
}

template <typename T> struct Matrix {
	vector<vector<T>> mat;
	Matrix() {}
	Matrix(vector<vector<T>> a) { mat = a; }
	Matrix(int n, int m) {
		mat.resize(n);
		for (int i = 0; i < n; i++) { mat[i].resize(m); }
	}

	int rows() const { return mat.size(); }
	int cols() const { return mat[0].size(); }

	// makes the identity matrix for a n by n matrix
	void makeiden() {
		for (int i = 0; i < rows(); i++) { mat[i][i] = 1; }
	}

	void print() const {
		for (int i = 0; i < rows(); i++) {
			for (int j = 0; j < cols(); j++) { cout << mat[i][j] << ' '; }
			cout << '\n';
		}
	}

    Matrix operator+=(const Matrix &b) {
		assert(rows() == b.rows() && cols() == b.cols());
		for (int i = 0; i < rows(); i++) {
			for (int j = 0; j < cols(); j++) {
				mat[i][j] += b.mat[i][j];
                mat[i][j] %= MOD;
            }
        }
		return *this;
	}

	Matrix operator+(const Matrix &b) const { return Matrix(*this) += b; }

	Matrix operator*=(const Matrix &b) {
		matmul(mat, b.mat);
		return *this;
	}

	Matrix operator*(const Matrix &b) const { return Matrix(*this) *= b; }

    Matrix operator^=(ll p) {
        assert(p >= 0);


        Matrix a(rows(), cols()), b(*this);
        a.makeiden();

        while (p){
            if (p&1) a *= b;
            b *= b;
            p >>= 1;
        }

        mat = a.mat;

		return *this;
	}

	Matrix operator^(ll p) const { return Matrix(*this) ^= p; }
};

/** 
 * DATASTRUCTURE: Lazy Segment Tree
 * PURPOSE: Segment Tree with lazy updates
 * TIME: O(log n) to update and query
*/
template <class Info, class Tag> class LazySegtree {
  private:
	const int n;
	vector<Info> tree;
	vector<Tag> lazy;

	/** builds the segtree values in O(N) time */
	void build(int v, int l, int r, const vector<Info> &a) {
		if (l == r) {
			tree[v] = a[l];
		} else {
			int m = (l + r) / 2;
			build(2 * v, l, m, a);
			build(2 * v + 1, m + 1, r, a);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	/** applies update x to lazy[v] and tree[v] */
	void apply(int v, int l, int r, const Tag &x) {
		tree[v].apply(x, l, r);
		lazy[v].apply(x);
	}

	/** pushes lazy updates down to the children of v */
	void push_down(int v, int l, int r) {
		int m = (l + r) / 2;
		apply(2 * v, l, m, lazy[v]);
		apply(2 * v + 1, m + 1, r, lazy[v]);
		lazy[v] = Tag();
	}

	void range_update(int v, int l, int r, int ql, int qr, const Tag &x) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(v, l, r, x);
		} else {
			push_down(v, l, r);
			int m = (l + r) / 2;
			range_update(2 * v, l, m, ql, qr, x);
			range_update(2 * v + 1, m + 1, r, ql, qr, x);
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}

	Info range_query(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return Info(); }
		if (l >= ql && r <= qr) { return tree[v]; }
		push_down(v, l, r);
		int m = (l + r) / 2;
		return range_query(2 * v, l, m, ql, qr) +
		       range_query(2 * v + 1, m + 1, r, ql, qr);
	}

  public:
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

	/** updates [ql, qr] with the arbitrary update chosen */
	void range_update(int ql, int qr, const Tag &x) {
		range_update(1, 0, n - 1, ql, qr, x);
	}

	/** @return result of range query on [ql, qr] */
	Info range_query(int ql, int qr) { return range_query(1, 0, n - 1, ql, qr); }
};

enum QueryType { ADD, NONE };

struct Tag {
	QueryType type = NONE;
	Matrix<ll> val = Matrix<ll>(vector<vl>{{1, 0}, {0, 1}});
	void apply(const Tag &t) {
		if (t.type == ADD) {
			val *= t.val;
            type = ADD;
		}
	}
};

struct Info {
	Matrix<ll> sum = Matrix<ll>(vector<vl>{{0}, {0}});
	void apply(const Tag &t, int l, int r) {
		sum = t.val * sum;
	}
};

/** @return result of joining nodes a and b together */
Info operator+(const Info &a, const Info &b) { return {a.sum + b.sum}; }

void solve(){
    int n, m; cin >> n >> m;

    Matrix<ll> fib = Matrix<ll>(vector<vl>{{1, 1}, {1, 0}});
    Matrix<ll> base = Matrix<ll>(vector<vl>{{0}, {1}});

    vector<Info> arr(n);
    rep(i, 0, n){
        ll a; cin >> a;
        Matrix<ll> m = fib;
        m ^= a;
        m *= base;
        arr[i] = {m};
    }

    LazySegtree<Info, Tag> st(arr);
    rep(i, 0, m){
        int c; cin >> c;
        int l, r; cin >> l >> r;
        --l; --r;
        if (c == 1){
            ll a; cin >> a;
            Matrix<ll> m = fib;
            m ^= a;
            st.range_update(l, r, Tag{ADD, m});
        } else {
            cout << st.range_query(l, r).sum.mat[0][0] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}