/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-02
 * Contest: 
 * Problem: 3219
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

    FT<int> st(k);
    vi cnt(k, 0);
    rep(i, 0, k - 1) {
        int x = arr[i];

        if (x >= k) continue;
        if (cnt[x] == 0) {
            st.set(x, 1);
        }
        cnt[x]++;
    }

    rep(i, k - 1, n) {
        int x = arr[i];
        if (x < k) {
            if (cnt[x] == 0) {
                st.set(x, 1);
            }
            cnt[x]++;
        }
        int j = i - k;
        if (j >= 0) {
            int x = arr[j];
            if (x < k) {
                cnt[x]--;
                if (cnt[x] == 0) {
                    st.set(x, 0);
                }
            }
        }

        int lo = 0, hi = k; 
        while (lo < hi) {
            int mid = (lo + hi + 1)/2;
            bool good = (mid == 0);
            if (mid != 0 && st.pref_sum(mid - 1) == mid) {
                good = true;
            }

            if (good) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        cout << lo << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}