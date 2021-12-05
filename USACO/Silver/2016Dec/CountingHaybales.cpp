/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

//ifstream fin("haybales.in");
//ofstream fout("haybales.out");
void solve(){
	int n, q;
	cin >> n >> q;
	unordered_map <int, int> haybales;
	for (int i = 0; i < n; ++i){
		int x; 
		cin >> x;
		// haybales.pb(x);
		haybales[x] = 1;
	}
	int positions[100000000];
	for (int i = 0; i < 100000000; ++i){
		positions[i] = 0;
	}
	positions[0] = haybales[0];
	for (int i = 1; i < n; ++i){
		positions[i] = positions[i - 1] + haybales[i];
	}
	for (int i = 0; i < q; ++i){
		int a, b;
		cin >> a >> b;
		cout << positions[b] - (a == 0 ? 0 : positions[a - 1]) << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    cout << "s";
    return 0;
}	