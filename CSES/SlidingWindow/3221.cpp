/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-02
 * Contest: 
 * Problem: 3221
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

/** DATASTRUCTURE: Extreme Queue
 *  PURPOSE: Maintains either minimum or maximum element in a queue
 *  SOURCE: O(1)
*/
template<typename T> struct ExtremeQueue {
	stack<pair<T, T>> s1, s2;

    const T UNIT = std::numeric_limits<T>().max();

    T f(T a, T b){
        return min(a, b);
    }

	T query() {
		if (s1.empty() && s2.empty()) { return UNIT; }
		if (s1.empty() || s2.empty()) {
			return s1.empty() ? s2.top().second : s1.top().second;
		}
		return f(s1.top().second, s2.top().second);
	}

	void push(T val) {
		s1.push({val, f(val, (s1.empty() ? val : s1.top().second))});
	}

	void pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				T ext = s2.empty() ? s1.top().first : s2.top().second;
				s2.push({s1.top().first, f(ext, s1.top().first)});
				s1.pop();
			}
		}
		s2.pop();
	}
};

void solve(){
    int n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vl arr(n, x);
    rep(i, 1, n) {
        arr[i] = (arr[i - 1] * a + b) % c;
    }
    
    ExtremeQueue<ll> q;

    ll sum = 0, ans = 0;
    rep(i, 0, k - 1) {
        q.push(arr[i]);
    }

    rep(i, k - 1, n) {
        q.push(arr[i]);
        int j = i - k;
        if (j >= 0) {
            q.pop();
        }

        // cout << sum << endl;

        ans ^= q.query();
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}