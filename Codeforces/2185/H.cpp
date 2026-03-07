/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-06
 * Contest: 
 * Problem: H
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

    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    vector<pii> brr;
    rep(i, 0, n) {
        brr.pb({arr[i], i});
    }

    sort(all(brr));
    reverse(all(brr));

    vl pre(n + 1, 0);
    rep(i, 0, n) {
        pre[i + 1] = pre[i] + arr[i];
    }

    FT<int> boss(n), bad(n);
    vector<pii> gap;

    rep(i, 0, n) {
        if (arr[i] > pre[i]) {
            gap.pb({arr[i] - pre[i], i});
            boss.set(i, 1);
        }
    }

    sort(all(gap));
    reverse(all(gap));

    int idx = 0;
    vi ans(n, 0);

    rep(i, 0, n) {
        ll x = brr[i].first;
        int j = brr[i].second;

        while (idx < sz(gap) && gap[idx].first > x) {
            bad.set(gap[idx].second, 1);
            idx++;
        }

        // eq or right
        int firstLose = lower_bound(all(pre), 2 * x) - pre.begin();
        firstLose--;
        firstLose = max(firstLose, j);

        if (firstLose - 1 >= j && boss.range_sum(firstLose, n - 1) <= k) {
            int lo = j, hi = firstLose - 1;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                int cheat = boss.range_sum(mid + 1, n - 1);
                if (cheat <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            ans[j] += firstLose - lo;
        }

        if (firstLose < n && k != 0) {
            int lo = firstLose, hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                int cheat = boss.range_sum(mid + 1, n - 1);
                if (cheat <= k - 1) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            ans[j] += n - lo;
        }

        ll b = boss.range_sum(j + 1, n - 1);

        // left
        firstLose = lower_bound(all(pre), x) - pre.begin();
        firstLose = min(firstLose, j);

        if (bad.range_sum(firstLose - 1, j - 1) + b <= k) {
            int lo = 0, hi = firstLose - 1;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                if (bad.range_sum(mid, j - 1) + b <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            ans[j] += firstLose - lo;
        }

        if (firstLose < j && 1 + bad.range_sum(j - 1, j - 1) + b <= k) {
            int lo = firstLose, hi = j - 1;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                if (1 + bad.range_sum(mid, j - 1) + b <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            ans[j] += j - lo;
        }
    }

    rep(i, 0, n) {
        cout << ans[i] << " ";
    }

    cout << endl;
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