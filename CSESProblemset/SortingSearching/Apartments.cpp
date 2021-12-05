/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;

	vector <int> applicants;
	multiset <int> apartments;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		applicants.pb(t);
	}

	sort(applicants.begin(), applicants.end());

	for (int i = 0; i < m; ++i){
		int t;
		cin >> t;
		apartments.insert(t);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		int z = applicants[i];
		if (apartments.size() == 0 || z - k > *(--apartments.end())){
			break;
		}
		int smallest = *apartments.lower_bound(z - k);
		if (smallest <= z + k){
			++ans;
			// cout << smallest << endl;
			apartments.erase(apartments.lower_bound(z - k));
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