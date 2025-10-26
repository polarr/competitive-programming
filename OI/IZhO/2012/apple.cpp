/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-25
 * Contest: IZhO 2012
 * Problem: apple
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

class SparseSegtree {
  private:
	struct Node {
		int freq = 0;
		int lazy = 0;
		Node *left = nullptr;
		Node *right = nullptr;
	};
	Node *root = new Node;
	const int n;

	int comb(int a, int b) { return a + b; }

	void apply(Node *cur, int len, int val) {
		if (val == 1) {
			(cur->lazy) = val;
			(cur->freq) = len * val;
		}
	}

	void push_down(Node *cur, int l, int r) {
		if ((cur->left) == nullptr) { (cur->left) = new Node; }
		if ((cur->right) == nullptr) { (cur->right) = new Node; }
		int m = (l + r) / 2;
		apply(cur->left, m - l + 1, cur->lazy);
		apply(cur->right, r - m, cur->lazy);
	}

	void range_set(Node *cur, int l, int r, int ql, int qr, int val) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(cur, r - l + 1, val);
		} else {
			push_down(cur, l, r);
			int m = (l + r) / 2;
			range_set(cur->left, l, m, ql, qr, val);
			range_set(cur->right, m + 1, r, ql, qr, val);
			(cur->freq) = comb((cur->left)->freq, (cur->right)->freq);
		}
	}

	int range_sum(Node *cur, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return 0; }
		if (ql <= l && r <= qr) { return cur->freq; }
		push_down(cur, l, r);
		int m = (l + r) / 2;
		return comb(range_sum(cur->left, l, m, ql, qr),
		            range_sum(cur->right, m + 1, r, ql, qr));
	}

  public:
	SparseSegtree(int n) : n(n) {}

	void range_set(int ql, int qr, int val) { range_set(root, 0, n - 1, ql, qr, val); }

	int range_sum(int ql, int qr) { return range_sum(root, 0, n - 1, ql, qr); }
};

const string iofilename = "f";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int m; cin >> m;

    SparseSegtree segtree(1e9 + 1);

    int add = 0;
    rep(i, 0, m){
        int c; cin >> c;
        int x, y;  cin >> x >> y;
        x += add;
        y += add;

        if (c == 1){
            add = segtree.range_sum(x, y);
            cout << add << endl;    
        } else {
            segtree.range_set(x, y, 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}