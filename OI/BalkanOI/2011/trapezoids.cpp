/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-07
 * Contest: Balkan OI 2011
 * Problem: trapezoids
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

const int MAX_N = 4e5 + 1;
const ll MOD = 30013;

/** 
 * DATASTRUCTURE: Segment Tree
 * PURPOSE: Range Updates and Queries
 * TIME: O(log n) to update and query
*/
template <class T> class SegmentTree {
  private:
	const T UNIT = {0, 0};

    T combine(T a, T b){
        if (a.first == b.first){
            return {a.first, (a.second + b.second) % MOD};
        }

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

    vector<array<int, 4>> trapezoids(n);
    vector<int> compress;
    rep(i, 0, n){
        int a, b, c, d; cin >> a >> b >> c >> d;
        trapezoids[i] = {b, a, c, d};
        compress.pb(a);
        compress.pb(b);
        compress.pb(c);
        compress.pb(d);
    }

    sort(all(compress));
    map<int, int> mp;
    int cnt = 1;
    rep(i, 0, compress.size()){
        if (i != 0 && compress[i] != compress[i - 1]){
            cnt++;
        }

        mp[compress[i]] = cnt;
    }

    rep(i, 0, n){
        rep(j, 0, 4){
            trapezoids[i][j] = mp[trapezoids[i][j]];
        }
    }

    sort(all(trapezoids));
    
    vector<pii> dp(n + 1, {0, 0});
    dp[n] = {0, 1};
    vector<pii> pp = dp;
    SegmentTree<pii> st(MAX_N + 1);
    st.set(MAX_N, {0, 1});

    priority_queue<pii> pq;

    for (int i = n - 1; i >= 0; i--){
        array<int, 4> t = trapezoids[i];

        while(!pq.empty() && pq.top().first > t[0]){
            int j = pq.top().second;
            pq.pop();
            
            st.set(trapezoids[j][2], pp[j]);
        }

        pii a = st.query(t[3] + 1, MAX_N + 1);
        a.first++;
        pii o = dp[i + 1];

        pp[i] = a;

        if (a.first == o.first){
            dp[i] = o;
            dp[i].second += a.second;
            dp[i].second %= MOD;
        } else {
            dp[i] = max(a, o);
        }
        
        pq.push({t[1], i});
    }

    cout << dp[0].first << " " << dp[0].second << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}