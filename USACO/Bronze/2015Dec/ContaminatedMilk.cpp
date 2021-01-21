/** Code by 1egend **/
// Problem: Contaminated Milk - USACO 2015 DEC BRONZE Q3
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("badmilk.in");
ofstream fout("badmilk.out");

void solve(){
	int n, m, d, s;
	fin >> n >> m >> d >> s;

	set <int> possible;
	for (int i = 1; i < m + 1; ++i){
		possible.insert(i);
	}
	vector<tuple<int, int, int>> drink;
	vector<pair<int, int>> sick;
	for (int i = 0; i < d; ++i){
		int a, b, c;
		fin >> a >> b >> c;
		drink.pb(make_tuple(a, b, c));
	}

	for (int i = 0; i < s; ++i){
		int a, b;
		fin >> a >> b;
		sick.pb(make_pair(a, b));
	}
	sort(drink.begin(), drink.end());
	for (int i = 0; i < s; ++i){
		pair <int, int> patient = sick[i];
		set <int> thisPossible;
		for (int k = 0; k < d; ++k){
			tuple <int, int, int> cup = drink[k];
			if (get<0>(cup) < patient.first){
				continue;
			}

			if (get<0>(cup) > patient.first){
				break;
			}

			if (get<2>(cup) < patient.second){
				int maybeMilk = get<1>(cup);
				thisPossible.insert(maybeMilk);
			}
		}
		set <int> temp;
		set_intersection(possible.begin(), possible.end(), thisPossible.begin(), thisPossible.end(), inserter(temp, temp.begin()));
		possible = temp;
	}

	int ans = 0;
	for (const int &bad : possible){
		int least = 0;
		int x = 0;
		for (int i = 0; i < d; ++i){
			tuple <int, int, int> cup = drink[i];
			if (get<1> (cup) == bad && get<0> (cup) > least){
				++x;
				least = get<0> (cup);
				// cout << least << " ";
			}
		}
		// cout << bad << endl;
		ans = max<int> (ans, x);
	}
	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	