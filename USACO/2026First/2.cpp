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

template <class T> class FT {
    private:
        int size;
        vector<T> bit;
        vector<T> arr;

    public:
	    FT(int size) : size(size), bit(size + 1), arr(size) {}

        void set(int ind, T val) { add(ind, val - arr[ind]); }

        void add(int ind, T val) {
            arr[ind] += val;
            ind++;
            for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
        }

        T pref_sum(int ind) {
            ind++;
            T total = 0;
            for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
            return total;
        }

        T range_sum(int l, int r) {
            return pref_sum(r) - pref_sum(l - 1);
        }
};

void solve(){
    int n; cin >> n;

    vi buckets(n);
    vector<pii> bucketsort(n);
    rep(i, 0, n) {
        cin >> buckets[i];
        bucketsort[i] = {buckets[i], i};
    }

    sort(all(bucketsort));

    FT<int> ft(n);
    rep(i, 0, n) {
        ft.set(i, 1);
    }

    ll ans = 0;
    int rem = n;
    deque<int> idx;
    for (int i = n - 1; i >= 0; i--) {
        int j = bucketsort[i].second;
        idx.pb(j);

        if (i == 0 || bucketsort[i - 1].first != bucketsort[i].first) {
            while (!idx.empty()) {
                int j1 = idx.front();
                int j2 = idx.back();

                int k1 = ft.pref_sum(j1);
                int k2 = ft.pref_sum(j2);

                int c1 = min(k1 - 1, rem - k1);
                int c2 = min(k2 - 1, rem - k2);

                if (c1 < c2) {
                    ans += c1;
                    ft.set(j1, 0);
                    idx.pop_front();
                } else {
                    ans += c2;
                    ft.set(j2, 0);
                    idx.pop_back();
                }

                rem--;
            }
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
        solve();
    }
    return 0;
}