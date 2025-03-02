/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-21
 * Contest: DMOJ dcc1
 * Problem: 4
**/

// rip forgot to use end exclusive ranges on segtree...

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

#include <bits/stdc++.h>
using namespace std;

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


class SparseSegtree {
  private:
	struct Node {
		ll freq = 0;
		ll lazy = 0;
		ll left = -1;
		ll right = -1;
	};
	vector<Node> tree;
	const ll n;
	ll timer = 0;

	ll comb(ll a, ll b) { return max(a, b); }

	void apply(ll cur, ll len, ll val) {
		tree[cur].lazy = val;
        tree[cur].freq = val;
	}

	void push_down(ll cur, ll l, ll r) {
		if (tree[cur].left == -1) {
			tree[cur].left = ++timer;
			tree.push_back(Node());
		}
		if (tree[cur].right == -1) {
			tree[cur].right = ++timer;
			tree.push_back(Node());
		}
		ll m = (l + r) / 2;
		apply(tree[cur].left, m - l + 1, tree[cur].lazy);
		apply(tree[cur].right, r - m, tree[cur].lazy);
	}

	void range_set(ll cur, ll l, ll r, ll ql, ll qr, ll val) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(cur, r - l + 1, val);
            //cout << "hi";
		} else {
            //debug_out(cur, l, r, ql, qr, val);
			push_down(cur, l, r);
			ll m = (l + r) / 2;
			range_set(tree[cur].left, l, m, ql, qr, val);
			range_set(tree[cur].right, m + 1, r, ql, qr, val);
			tree[cur].freq =
			    comb(tree[tree[cur].left].freq, tree[tree[cur].right].freq);
		}
	}

	ll range_sum(ll cur, ll l, ll r, ll ql, ll qr) {
		if (qr < l || ql > r) { return LLONG_MIN; }
		if (ql <= l && r <= qr) { return tree[cur].freq; }
		push_down(cur, l, r);
		ll m = (l + r) / 2;
		return comb(range_sum(tree[cur].left, l, m, ql, qr),
		            range_sum(tree[cur].right, m + 1, r, ql, qr));
	}

    void printTree(){
        rep(i, 0, tree.size()){
            cout << tree[i].freq << endl;
        }
    }

  public:
	SparseSegtree(ll n, ll q = 0) : n(n) {
		if (q > 0) { tree.reserve(2 * q * __lg(n)); }
		tree.push_back(Node());
	}

    void print(){
        printTree();
    }

	void range_set(ll ql, ll qr, ll val) { debug_out(ql, qr, val); range_set(0, 0, n - 1, ql, qr, val); }

	ll range_sum(ll ql, ll qr) { return range_sum(0, 0, n - 1, ql, qr); }
};

void solve(){
    int n, k; cin >> n >> k;

    int unknown = 0, known = 0;
    vl arr(n);
    rep(i, 0, n){
        cin >> arr[i];
        if (arr[i] == -1){
            unknown++;
        } else {
            known++;
        }
    }

    if (unknown >= k || (unknown == k - 1 && known > 0)){
        cout << "Infinity" << endl;
        return;
    }

    if (k == n){
        int ans = INT_MAX;
        int first = -1;
        rep(i, 0, n){
            if (arr[i] == -1){
                continue;
            }

            if (first == -1){
                first = i;
                continue;
            }

            if (arr[first] > arr[i]){
                cout << -1 << endl;
                return;
            }

            ans = min(ans, (int)(arr[i] - arr[first])/(i - first));

            first = i;
        }
        cout << ans << endl;
        return;
    }


    SparseSegtree st(1e8, 3000);
    st.range_set(0, 40, 90);
    debug_out(st.range_sum(1, 100));
    return;

    int mem = 0;

    auto check = [&](ll g){
        mem++;
        SparseSegtree st(1e15, 2 * n + 1);
        ll add = 1e14;
        ll cnt = 0;
        rep(i, 0, n){
            if (arr[i] == -1){
                cnt++;
                // implicitly add 1 to everything
                // implicitly shift everything +g
                continue;
            }

            ll lis = st.range_sum(0, arr[i] - g - cnt * g + 1 + add) + 1;
            st.range_set(arr[i] - cnt * g + add, arr[i] - cnt * g + 1 + add, (ll)lis);
        }

        ll mx = st.range_sum(0, 1e15) + cnt;

        return mx >= k;
    };

    // bruh some sparse segtree issue is killing AC
    // I FORGOT TO USE EXCLUSIVE RANGES

    // auto check = [&](ll g){
    //     vl dp(n + 1, INT_MAX);
    //     dp[0] = -INT_MAX;
    //     rep(i, 0, n){
    //         // debug_out(dp);
    //         if (arr[i] == -1){
    //             for (int j = n; j > 0; j--){
    //                 ll nx = dp[j - 1];
    //                 if (nx == INT_MAX){
    //                     continue;
    //                 }

    //                 if (nx == -INT_MAX){
    //                     dp[j] = nx;
    //                     continue;
    //                 }

    //                 dp[j] = nx + g;
    //             }
    //             continue;
    //         }

    //         auto idx = upper_bound(dp.begin(), dp.end(), arr[i] - g);
    //         if (idx != dp.end()){
    //             dp[idx - dp.begin()] = min(dp[idx - dp.begin()], arr[i]);
    //         }
    //     }

    //     for (int i = n; i >= 0; i--){
    //         if (dp[i] != INT_MAX){
    //             return i >= k;
    //         }
    //     }
    // };

    // binary search on G
    ll low = 0, high = 1e9;
    while (low < high){
        ll mid = (low + high + 1)/2;
        if (check(mid)){
            low = mid;
        } else {
            high = mid - 1;
        }
    };

    if (low == 0 && !check(0)){
        cout << -1 << endl;
        return;
    }

    cout << low << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}