/** Code by 1egend **/
// Problem: Fench Painting, USACO 2015 DEC BRONZE Q1
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("paint.in");
ofstream fout("paint.out");

void solve(){
	int a, b, c, d;
	fin >> a >> b >> c >> d;
	if ((a <= d && b >= c) || (c <= b && d >= a)){
		fout << max<int>(b, d) - min<int>(a, c);
	}
	else{
		fout << b - a + d - c;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	