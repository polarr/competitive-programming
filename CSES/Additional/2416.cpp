/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-10
 * Contest: CSES Problemset - Range Queries
 * Problem: 2416
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

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
    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    vector<ll> diff(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll curr = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > curr){
            curr = arr[i];
        }

        diff[i] = curr - arr[i];
    }

    vector<ll> prediff(n + 1);
    prediff[0] = 0;
    for (int i = 1; i < n + 1; i++){
        prediff[i] = diff[i - 1] + prediff[i - 1];
    }

    vector<vector<pair<int, int>>> queries(n);
    FT<ll> contrib(n);
    vector<ll> ans(q);

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        queries[a].pb({b, i});
    }

    vector<pair<ll, ll>> mins;

    for (int i = n - 1; i >= 0; i--){
        while (!mins.empty()){
            pair<ll, ll> k = mins[mins.size() - 1];
            if (k.second < diff[i]){
                break;
            }

            contrib.set(mins.size() - 1, 0);
            mins.pop_back();
        }

        ll len = mins.empty() ? n - i : mins[mins.size() - 1].first - i;
        mins.pb({i, diff[i]});
        contrib.set(mins.size() - 1, diff[i] * len);

        // solve queries
        for (auto [b, j] : queries[i]){
            ll t = prediff[b + 1] - prediff[i];

            auto ii = upper_bound(mins.begin(), mins.end(), pair<ll, ll>{b, LLONG_MAX}, greater<>());
            // cout << ii - mins.begin() << endl;

            t -= contrib.pref_sum(mins.size() - 1) - contrib.pref_sum(ii - mins.begin());

            t -= (*ii).second * ((ll)b - (*ii).first + 1);

            ans[j] = t;
        }
    }

    for (int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}