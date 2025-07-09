/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-08
 * Contest: 
 * Problem: sails
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
        if (ind == -1) return T();
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}

    /** @return The sum of all values in [start, end]. */
    T pref_sum(int start, int end){
        if (end < start) return T();
        return pref_sum(end) - pref_sum(start - 1);
    }
};

/** 
 * DS: Disjoint Set Union 
 * PURPOSE: Dynamically updates connectedness of graph by adding edges
 * TIME: amortized O(a(N)) to query
*/
class DSU {
    private: 
        vector<int> parents;
        vector<int> previous;
        vector<int> sizes;
    
    public:
        DSU(int size) : parents(size), previous(size), sizes(size, 1){
            for (int i = 0; i < size; i++){
                parents[i] = i;
                previous[i] = i - 1;
            }
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        int findPrev(int x){
            return previous[find(x)];
        }

        bool unite(int a, int b){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return false;
            }

            if (parentA > parentB){
                swap(parentA, parentB);
            }

            sizes[parentB] += sizes[parentA];
            previous[parentB] = previous[parentA];
            parents[parentA] = parentB;
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

// very funny solution...

void solve(){
    int n; cin >> n;

    vector<pii> masts(n);
    rep(i, 0, n){
        cin >> masts[i].first >> masts[i].second;
    }

    FT<ll> st(2 * n + 5);
    DSU dsu(2 * n + 5);

    int zero = n + 2;

    sort(all(masts));
    int lst = 0;
    rep(i, 0, n){
        st.add(zero, masts[i].first - lst);
        int k = masts[i].second;
        // rep(j, 0, 2 * h + 5){
        //     if (j == zero) cerr << "[";
        //     cerr << st.pref_sum(j, j) << " ";
        // }
        // cerr << endl;
        int lo = zero, hi = 2 * n + 4;
        while (lo < hi){
            int mid = (lo + hi)/2;
            if (st.pref_sum(zero, mid) >= k){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int nx = dsu.find(lo + 1);

        if (lo == zero){
            st.add(zero, -k);
            st.add(nx, k);
            lst = masts[i].first;
            continue;
        }

        int pv = dsu.findPrev(lo);

        int rem = k - st.pref_sum(zero, pv);
        st.add(lo, -rem + st.pref_sum(dsu.findPrev(pv) + 1, pv));
        st.set(pv, 0);
        dsu.unite(pv, lo);
        st.add(nx, rem);
        zero--;

        lst = masts[i].first;
    }
    
    ll ans = 0;
    ll c = 0;
    rep(i, zero, 2 * n + 5){
        if (i != dsu.find(i)){
            i = dsu.find(i) - 1;
            continue;
        }
        ll cnt = st.pref_sum(i, i);
        ans += cnt * (c * (c - 1))/2;
        c++;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}