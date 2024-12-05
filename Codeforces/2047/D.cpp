/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-02
 * Contest: Codeforces 2047
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = std::numeric_limits<T>().max();

	vector<T> segtree;
	int len;

  public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_min(int start, int end) {
		T min = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
			if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
		}
		return min;
	}
};

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    MinSegmentTree<int> tree(n);
    map<int, int> last;

    int target = INT_MAX;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        tree.set(i, arr[i]);
        last[arr[i]] = i;
    }

    vector<pair<int, int>> ans;
    vector<int> other;
    int minOther = INT_MAX;

    int st = 0;

    while(st != n){
        int mn = tree.range_min(st, n);
        if (mn > minOther){
            for (int i = st; i < n; i++){
                other.pb(arr[i] + 1);
            }
            break;
        }
        int l = last[mn];
        int cnt = 0;
        for (int i = st; i <= l; i++){
            if (arr[i] == mn){
                cnt++;
                continue;
            }
            other.pb(arr[i] + 1);
            minOther = min(minOther, arr[i] + 1);
        }

        ans.pb({mn, cnt});
        st = l + 1;
    }

    sort(other.begin(), other.end());

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].second; j++){
            cout << ans[i].first << " ";
        }
    }

    for (int i = 0; i < other.size(); i++){
        cout << other[i] << " ";
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