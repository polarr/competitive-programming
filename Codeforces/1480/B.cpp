/** Code by 1egend **/
// Problem: Codeforces 1480 B. The Great Hero
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	int A, B, n;
	cin >> A >> B >> n;
	vector <pair<int, int>> monsters(n, make_pair(0, 0));
	for (int i = 0; i < n; ++i){
		int a;
		cin >> a;
		monsters[i].first = a;
	}
	for (int i = 0; i < n; ++i){
		int a;
		cin >> a;
		monsters[i].second = a;
	}
	sort(monsters.begin(), monsters.end());
	for (int i = 0; i < n; ++i){
		B -= ceil(monsters[i].second/(A * 1.0)) * monsters[i].first;
		if (B <= 0){
			if (i == n - 1 && B > -monsters[i].first){
				cout << "YES" << endl;
				return;
			}
			else{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        // cout << "Case #" << t  << ": " << endl;
        solve();
    }
    return 0;
}	