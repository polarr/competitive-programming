/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n, m;
	cin >> n >> m;
	vector <int> prices;
	vector <int> customers;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		prices.push_back(t);
	}
	sort(prices.begin(), prices.end());
	for (int i = 0; i < m; ++i){
		int t;
		cin >> t;
		customers.push_back(t);
	}
	for (int i = 0; i < m; ++i){
		if (n == 0){
			cout << -1 << endl;
			continue;
		}
		int t = customers[i];
		for (int x = 0; x < n; ++x){
			if (prices[x] > t){
				if (x == 0){
					cout << -1 << endl;
				}	
				else{
					cout << prices[x - 1] << endl;
					prices.erase(prices.begin() + x - 1);
					--n;
				}
				break;
			}
			if (x == n - 1){
				cout << prices[x] << endl;
				prices.erase(prices.begin() + x);
				--n;
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	