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
	vector <int> z;
	for (int i = 0; i < x; ++i){
		int k;
		cin >> k;
		z.push_back(k);
	}
	sort(z.begin(), z.end());
	z.push_back(INT_MAX);
	bool values[z[x - 1] + 1];
	int count = 1;
	values[z[0]] = true;
	for (int i = 1; i < x; ++i){
		if (z[i] != z[i - 1]){
			if (!values[z[i - 1]]){
				values[z[i - 1]] = true;
			}
			else{
				values[z[i]] = true;
			}
			count = 1;
		}
		else{
			++count;
			if (count > 1){
				if (!values[z[i]]){
					values[z[i]] = true;
				}
				else{
					values[z[i + 1]] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < z[x - 1] + 1; ++i){
		if (values[i]){
			ans ++;
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