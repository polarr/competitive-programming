/** Code by 1egend **/
// Problem: CCC S2 Modern Art
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	int m, n, k;
	cin >> m >> n >> k;
	vector <int> r(m, 0);
	vector <int> c(n, 0);
	for (int i = 0; i < k; ++i){
		char a; int b;
		cin >> a >> b;
		if (a == 'R'){
			r[b - 1] = !r[b - 1]; 
		}
		else{
			c[b - 1] = !c[b - 1]; 
		}
	}
	int rows = 0, cols = 0;
	for (int i = 0; i < m; ++i){
		rows += (r[i] == 1);
	}
	for (int i = 0; i < n; ++i){
		cols += (c[i] == 1);
	}
	cout << n * rows + m * cols - 2 * rows * cols;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	