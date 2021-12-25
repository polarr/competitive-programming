/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("lostcow.in");
ofstream fout("lostcow.out");

void solve(){
	int x, y;
	fin >> x >> y;

	int ans = 0;
	int i = 1;
	int n = 0;
	while(true){
		ans += i + floor(i/2.0);
		if (!n){
			if (y >= x && y <= x + i){
				ans -= abs(x + i - y);
				break;
			}
		}
		else if (y <= x && y >= x - i){
			ans -= abs(x - i - y);
			break;
		}
		i *= 2;
		n = !n;
	}
	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	