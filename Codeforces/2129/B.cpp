/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-31
 * Contest: 
 * Problem: B
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
};

void solve(){
    int n; cin >> n;
    FT<int> st1(2 * n), st2(2 * n);
    vi arr(n);
    vi up(n, 0), down(n, 0);
    rep(i, 0, n){
        cin >> arr[i];
        --arr[i];
    }

    int ans = 0;

    rep(i, 0, n){
        down[i] = i - st1.pref_sum(arr[i]);
        ans += down[i];
        st1.set(arr[i], 1);
    }

    for (int i = n - 1; i >= 0; i--){
        if (arr[i] != 0) up[i] = st2.pref_sum(arr[i] - 1);
        st2.set(arr[i], 1);
    }

    rep(i, 0, n){
        if (n - i - 1 - up[i] < down[i]){
            ans += n - i - 1 - up[i] - down[i];
        }
    }

    cout << ans << endl;
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