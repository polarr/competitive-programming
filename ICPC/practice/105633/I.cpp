/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-09
 * Contest: ICPC Practice Codeforces 105633
 * Problem: I
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
 * DATASTRUCTURE: Segment Tree
 * PURPOSE: Range Updates and Queries
 * TIME: O(log n) to update and query
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = std::numeric_limits<T>().min();

    T combine(T a, T b){
        return max(a, b);
    }

	vector<T> segtree;
	int len;

  public:
	SegmentTree(int len) : len(len), segtree(len * 2, UNIT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = combine(segtree[ind], segtree[ind ^ 1]);
		}
	}

    // [start, end)
	T query(int start, int end) {
		T ans = UNIT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { ans = combine(ans, segtree[start++]); }
			if (end % 2 == 1) { ans = combine(ans, segtree[--end]); }
		}
		return ans;
	}
};

void solve(){
    int n; cin >> n;

    vector<vi> d(MAX_N, {-1});
    vi di(MAX_N, 0);
    vector<vi> ds(n);
    SegmentTree<int> st(MAX_N);

    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];

        int x = arr[i];
        int rt = sqrt(x);
        if (rt * rt == x){
            d[rt].pb(i);
            ds[i].pb(rt);
        } else {
            rt++;
        }

        rep(j, 1, rt){
            if (x % j == 0){
                d[j].pb(i);
                ds[i].pb(j);

                d[x/j].pb(i);
                ds[i].pb(x/j);
            }
        }
    }

    int q; cin >> q;

    vi ans(q);
    vector<vector<pii>> queries(n);
    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;
        queries[b].pb({a, i});
    }

    rep(i, 0, n){
        for (int f : ds[i]){
            di[f]++;
            int last = d[f][di[f] - 1];
            st.set(f, last);
        }

        for (auto &[a, idx] : queries[i]){
            int lo = 1;
            int hi = MAX_N;

            while (lo < hi){
                int mid = (lo + hi)/2;

                if (st.query(mid + 1, MAX_N) >= a){
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }

            ans[idx] = lo;
        }
    }

    for (int a : ans){
        cout << a << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}