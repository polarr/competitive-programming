/** Code by 1egend **/
// Problem: B. Card Deck
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

int maxIndex(vector<int> arr){
	int mx = arr[0];
	int ans = 0;
	for (int i = 1; i < arr.size(); ++i){
		if (arr[i] >= mx){
			mx = arr[i];
			ans = i;
		}
	}
	return ans;
}

void solve(){
	int x;
	cin >> x;
	vector<int> arr;
	for (int i = 0; i < x; ++i){
		int a;
		cin >> a;
		arr.pb(a);
	}
	vector <int> n;
	while (arr.size() > 0){
		int z = maxIndex(arr);
		for (int i = z; i < arr.size(); ++i){
			n.pb(arr[i]);
			arr.erase(arr.begin() + i);
			--i;
		}
	}
	for (int i = 0; i < x; ++i){
		cout << n[i] << " ";
	}
	cout << endl;
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