/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n, m;
	cin >> n >> m;
	multiset <int> prices;
	vector <int> customers;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		prices.insert(t);
	}
	for (int i = 0; i < m; ++i){
		int t;
		cin >> t;
		customers.pb(t);
	}

	for (int i = 0; i < m; ++i){
		int customer = customers[i];
		if (prices.size() == 0){
			cout << -1 << endl;
			continue;
		}
		auto iterator = prices.upper_bound(customer);
		if (iterator == prices.begin()){
			cout << -1 << endl;
			continue;
		}

		--iterator;
		cout << *iterator << endl;
		prices.erase(iterator);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	