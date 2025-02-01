/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-31
 * Contest: Baltic OI 2015
 * Problem: 5 - hacker
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

/** DATASTRUCTURE: ExtremeQueue
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
    int n; cin >> n;
    vi arr(n);
    rep(i, 0, n){
        cin >> arr[i];
    }
    int can = n - n/2;
    vi sum(n, 0);
    rep(i, 0, can){
        sum[0] += arr[i];
    }

    auto idx = [&](int i){
        if (i < 0){
            return n + (i % n);
        }

        return i % n;
    };

    rep(i, 1, n){
        sum[i] = sum[i - 1] - arr[i - 1];
        sum[i] += arr[idx(can + i - 1)];
    }

    // debug_out(sum);

    ExtremeQueue<int> minQueue;
    int ans = 0;
    rep(j, -can + 1, 1){
        minQueue.push(sum[idx(j)]);
    }

    ans = max(ans, minQueue.query());
    rep(i, 1, n){
        minQueue.pop();
        minQueue.push(sum[i]);
        ans = max(ans, minQueue.query());
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}