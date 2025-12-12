/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-10
 * Contest: 
 * Problem: 3223
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
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}

    T range_sum(int l, int r) {
        if (r < l) return T();
        if (l == 0) {
            return pref_sum(r);
        }

        return pref_sum(r) - pref_sum(l - 1);
    }
};

void solve(){
    int n, k; cin >> n >> k;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    vi arr_sort = arr;
    sort(all(arr_sort));
    arr_sort.erase(unique(all(arr_sort)), arr_sort.end());

    auto compress = [&](int x) -> int {
        return lower_bound(all(arr_sort), x) - arr_sort.begin();
    };

    rep(i, 0, n) {
        arr[i] = compress(arr[i]);
    }

    FT<int> ft1(n + 1), ft2(n + 1);

    vi pre(n), suf(n);
    rep(i, 0, n) {
        int j = i + k - 1;
        if (j < n) {
            pre[j] -= ft1.range_sum(arr[j] + 1, n);
        }
        if (i >= k - 1) {
            pre[i] += ft1.range_sum(arr[i] + 1, n);
        }
        ft1.add(arr[i], 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        int j = i - k + 1;
        if (j >= 0) {
            suf[j] -= ft2.range_sum(0, arr[j] - 1);
        }
        if (i <= n - k) {
            suf[i] += ft2.range_sum(0, arr[i] - 1);
        }
        ft2.add(arr[i], 1);
    }

    FT<int> ft3(n + 1);
    ll curr = 0;
    rep(i, 0, k - 1) {
        curr += ft3.range_sum(arr[i] + 1, n);
        ft3.add(arr[i], 1);
    }

    rep(i, k - 1, n) {
        curr += pre[i];
        if (i >= k) curr -= suf[i - k];

        cout << curr << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}