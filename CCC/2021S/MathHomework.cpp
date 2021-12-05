/** Code by 1egend **/
// Problem: CCC S5 2021 Math Homework
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");
int gcd(int a, int b){
    if (a == 1 || b == 1){
    	return 1;
    }
    if (a == b){
        return a;
    }
  
    if (a > b){
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}

int lcm(int a, int b) { 
	if (a == 1){
		return b;
	}
	if (b == 1){
		return a;
	}
    return (a / gcd(a, b)) * b; 
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector <int> a(n, 1);
	vector <tuple<int, int, int>> z;
	for (int i = 0; i < m; ++i){
		int k, b, c;
		cin >> k >> b >> c;
		z.pb(make_tuple(k, b, c));
		for (int x = k - 1; x < b; ++x){
			a[x] = lcm(a[x], c);
		}
		
	}
	for (int i = 0; i < m; ++i){
		int k = get<0>(z[i]), b = get<1>(z[i]), c = get<2>(z[i]);
		int g = a[k - 1];
		for (int x = k; x < b; ++x){
			g = gcd(g, a[x]);
		}
		if (g != c){
			cout << "Impossible";
			return;
		}
	}
	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	