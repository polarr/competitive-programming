/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: CSES Problemset
 * Problem: 1724
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

struct Trop {
    ll val = LLONG_MAX;
    Trop operator*=(const Trop &b){
        if (val == LLONG_MAX || b.val == LLONG_MAX) {
            val = LLONG_MAX;
        } else {
            val += b.val;
        }
        return *this;
    }
    Trop operator*(const Trop &b){
        return Trop(*this) *= b;
    }
    Trop operator+=(const Trop &b){
        val = min(val, b.val);
        return *this;
    }
    Trop operator+(const Trop &b){
        return Trop(*this) += b;
    }
    static Trop zero() { return Trop(); }
    static Trop one()  { return {0};   }
};

/** 
 * DATASTRUCTURE: Matrix
 * PURPOSE: Generic matrix template
 * TIME: Supports binary exponentiation, O(nmp) for n x m times m x p matrix
 * SOURCE: USACO Guide
*/
template <typename T> void matmul(vector<vector<T>> &a, vector<vector<T>> b) {
	int n = a.size(), m = a[0].size(), p = b[0].size();
	assert(m == sz(b));
	vector<vector<T>> c(n, vector<T>(p));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
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
		for (int i = 0; i < rows(); i++) { mat[i][i] = Trop::one(); }
	}

	void print() const {
		for (int i = 0; i < rows(); i++) {
			for (int j = 0; j < cols(); j++) { 
                ll v = mat[i][j].val;
                cout << (v == LLONG_MAX ? "zero" : (v == 0 ? "one" : to_string(v))) << ' '; 
            }
			cout << '\n';
		}
	}

	Matrix operator*=(const Matrix &b) {
		matmul<T>(mat, b.mat);
		return *this;
	}

	Matrix operator*(const Matrix &b) { return Matrix(*this) *= b; }

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

	Matrix operator^(ll p) { return Matrix(*this) ^= p; }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;

    Matrix<Trop> mat(n, n), v(n, 1);
    v.mat[0][0] = {0};
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        ll c; cin >> c;
        mat.mat[b][a] += {c};
    }

    mat ^= k;
    mat *= v;

    ll ans = mat.mat[n - 1][0].val;

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}