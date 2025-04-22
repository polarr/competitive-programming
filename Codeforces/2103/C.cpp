/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-21
 * Contest: Codeforces 2103
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
 * DATASTRUCTURE: Fenwick Tree
 * PURPOSE: Point update and prefix sums
 * TIME: O(log n) to update and query
*/
template <class T> class FT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	FT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
        if (ind < 0){
            return 0;
        }

		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}

    /** @return The sum of all values in [0, ind]. */
	T pref_sum(int start, int end) {
		return pref_sum(end) - pref_sum(start - 1);
	}
};

void solve(){
    int n, k; cin >> n >> k;

    vi a(n);
    int s = 0;

    rep(i, 0, n){
        cin >> a[i];

        if (a[i] <= k){
            s++;
        } else {
            s--;
        }
    }

    FT<int> st(2 * n + 1);

    vi prefix(n, 0), suffix(n, 0);

    rep(i, 0, n){
        if (i != 0) prefix[i] = prefix[i - 1];
        if (a[i] <= k){
            prefix[i]++;
        } else {
            prefix[i]--;
        }
    }

    vi b = a;
    reverse(all(b));

    rep(i, 0, n){
        if (i != 0) suffix[i] = suffix[i - 1];
        if (b[i] <= k){
            suffix[i]++;
        } else {
            suffix[i]--;
        }

        st.add(suffix[i] + n, 1);
    }

    st.add(suffix[n - 1] + n, -1);

    rep(i, 0, n - 2){
        st.add(suffix[n - 2 - i] + n, -1);
        if (prefix[i] < 0){
            int t = s - prefix[i];
            if (t >= 0 && st.pref_sum(n, t + n) > 0){
                cout << "YES" << endl;
                return;
            }
        } else {
            int t = s - prefix[i];
            if (t >= 0 || st.pref_sum(t + 1 + n, -1 + n) != (n - 2 - i)){
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}