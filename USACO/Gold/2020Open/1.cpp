/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-31
 * Contest: USACO 2020 Open Gold
 * Problem: 1
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

const string iofilename = "haircut";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

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
    int n; fin >> n;
    vi arr(n);
    rep(i, 0, n){
        fin >> arr[i];
    }

    FT<int> st(n + 1);
    vl inversions(n + 1, 0);

    ll inv = 0;

    rep(i, 0, n){
        ll count = st.pref_sum(n) - st.pref_sum(arr[i]);
        st.add(arr[i], 1);
        inv += count;
        inversions[arr[i]] += count;
    }

    vl ans(n, 0);

    for (int i = n - 1; i >= 0; i--){
        inv -= inversions[i];
        ans[i] = inv;
    }
    
    rep(i, 0, n){
        fout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}