/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-05
 * Contest: COCI 2020
 * Problem: sjeckanje
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

const ll mn = -1e18;

/** 
 * DATASTRUCTURE: Recursive Segment Tree
 * PURPOSE: Segment Tree with more extensibility
 * TIME: O(log n) to update and query, but worse constant factor than the iterative version
*/
template <class T> class RecSegmentTree {
  private:
	const T UNIT = T{mn, mn, 0, 0, 0, 0};

	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { 
        if (b[0] == mn){
            return a;
        }

        if (a[0] == mn){
            return b;
        }
        array<ll, 6> ans = {a[0], b[1], mn, mn, mn, mn};

        ans[2] = max({a[2] + b[4], a[3] + b[2], a[2] + b[2]});
        ans[3] = max({a[2] + b[5], a[2] + b[3], a[3] + b[3]});
        ans[4] = max({a[4] + b[4], a[4] + b[2], a[5] + b[2]});
        ans[5] = max({a[4] + b[5], a[4] + b[3], a[5] + b[3]});

        if ((a[1] > 0 && b[0] > 0) || (a[1] < 0 && b[0] < 0)){
            // combine
            ans[2] = max(ans[2], a[3] + b[4]);
            ans[3] = max(ans[3], a[3] + b[5]);
            ans[4] = max(ans[4], a[5] + b[4]);
            ans[5] = max(ans[5], a[5] + b[5]);
        }

        return ans;
    }

	void build(const vector<T> &arr, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = arr[at_left];
			return;
		}
		int mid = (at_left + at_right) / 2;
		build(arr, 2 * at, at_left, mid);
		build(arr, 2 * at + 1, mid + 1, at_right);
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	void set(int ind, T val, int at, int at_left, int at_right) {
		if (at_left == at_right) {
			segtree[at] = val;
			return;
		}
		int mid = (at_left + at_right) / 2;
		if (ind <= mid) {
			set(ind, val, 2 * at, at_left, mid);
		} else {
			set(ind, val, 2 * at + 1, mid + 1, at_right);
		}
		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

	T range_sum(int start, int end, int at, int at_left, int at_right) {
		if (at_right < start || end < at_left) { return UNIT; }
		if (start <= at_left && at_right <= end) { return segtree[at]; }
		int mid = (at_left + at_right) / 2;
		T left_res = range_sum(start, end, 2 * at, at_left, mid);
		T right_res = range_sum(start, end, 2 * at + 1, mid + 1, at_right);
		return combine(left_res, right_res);
	}

  public:
	RecSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, UNIT); };

	RecSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, UNIT);
		build(arr, 1, 0, len - 1);
	}

	void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    // [start, end]
	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }
};

/** TOOL: Debug
 *  PURPOSE: Prints various data types to terminal
 *  SOURCE: tourist
*/
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

void solve(){
    int n, q; cin >> n >> q;

    vl a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vl d(n, a[0]);
    rep(i, 1, n){
        d[i] = a[i] - a[i - 1];
    }

    auto create = [&](ll k){
        return array<ll, 6>{k, k, 0, mn, mn, abs(k)};
    };

    vector<array<ll, 6>> arr(n);
    rep(i, 0, n){
        arr[i] = create(d[i]);
    }

    RecSegmentTree<array<ll, 6>> st(arr);

    rep(i, 0, q){
        int l, r; ll x;
        cin >> l >> r >> x;

        --l; --r;
        d[l] += x;
        if (r != n - 1) d[r + 1] -= x;

        // debug_out(d);

        st.set(l, create(d[l]));
        if (r != n - 1) st.set(r + 1, create(d[r + 1]));

        array<ll, 6> ans = st.range_sum(1, n - 1);

        // debug_out(ans);

        cout << max(max(max(ans[2], ans[3]), ans[4]), ans[5]) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}