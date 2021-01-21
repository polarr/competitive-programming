/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	int x;
	cin >> x;
	vector <int> n;
	for (int i = 0; i < x; ++i){
		int z;
		cin >> z;
		n.push_back(z);
	}
	sort(n.begin(), n.end());
	if (x % 2){
		cout << n[x/2];
	}
	for (int i = 0; i < floor(x/2.0); ++i){
		cout << n[i] << " " << n[x - i - 1] << " ";
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