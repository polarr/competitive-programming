/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int x;
    cin >> x;
    vector <int> n;
    int sum = 0;
    for (int i = 0; i < x; i++){
        int k;
        cin >> k;
        n.push_back(k);
        sum += k;
    }
    sort(n.begin(), n.end(), greater<int>());
    int diff = ceil(sum/2.0);
    for (int i = 0; i < x; ++i){
        if (n[i] > diff){
            continue;
        }

        diff -= n[i];
        if (diff == 0){
            break;
        }
    }
    cout << ceil(sum/2.0) - floor(sum/2.0) + diff << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // cout << "Case #" << t  << ": " << endl;
    solve();
    return 0;
}