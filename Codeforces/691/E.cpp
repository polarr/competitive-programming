/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-25
 * Contest: Codeforces 691
 * Problem: E
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

	Matrix operator*=(const Matrix &b) {
		matmul(mat, b.mat);
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
    int n; cin >> n;
    ll k; cin >> k;
    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    Matrix<ll> m(n, n), v(n, 1);
    rep(i, 0, n){
        rep(j, 0, n){
            ll t = arr[i] ^ arr[j];
            int cnt = 0;
            while (t){
                if (t & 1){
                    cnt++;
                }
                t >>= 1;
            }

            if (cnt % 3 == 0){
                m.mat[i][j] = 1;
            }
        }
    }

    rep(i, 0, n){
        v.mat[i][0] = 1;
    }

    k--;
    m ^= k;
    m *= v;

    ll ans = 0;
    rep(i, 0, n){
        ans += m.mat[i][0];
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}