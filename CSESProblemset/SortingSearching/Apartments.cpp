/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

vector<int> cinVector(int n){
	vector <int> ans;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		ans.push_back(t);
	}
	return ans;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> a = cinVector(n);
	vector <int> b = cinVector(m);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = 0;
	for (int i = 0; i < n; ++i){
		if (m == 0 || b[0] > a[n - 1] + k){
			break;
		}
		int least = a[i] - k;
		int most = least + 2 * k;
		for (int z = 0; z < m; ++z){
			if (b[z] >= least && b[z] <= most){
				++ans;
				--m;
				b.erase(b.begin() + z);
				break;
			}
			if (b[z] < least){
				b.erase(b.begin() + z);
				--m;
				--z;
			}
		}
	}
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	