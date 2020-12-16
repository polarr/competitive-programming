/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	string k;
	getline(cin, k);
	vector <string> a;
	int m = 0;
	a.push_back("");

	int ind;
	for (int i = 2; i < k.length() - 1; ++i){
		if (k[i] == ','){
			a.push_back("");
			m ++;
		}
		else if (k[i] == ']'){
			ind = i;
			break;
		}
		else{
			a[m] += k[i];
		}
	}

	string target = k.substr(ind + 2, k.length() - (ind + 2) - 1);

	for (int i = 0; i < a.size(); ++i){
		string card = a[i];
		//cout << card << endl;
		if (card.substr(0, card.length() - 2) == target.substr(0, target.length() - 2) || card[card.length() - 1] == target[target.length() - 1] || card == "wildcard"){
			cout << "true";
			return;
		}
	}
	cout << "false";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	