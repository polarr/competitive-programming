/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-12
 * Contest: CSES Problemset
 * Problem: 2136. Advanced Techniques - Hamming Distance
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;

    vector<bitset<30>> str(n);

    for (int i = 0; i < n; i++){
        bitset<30> a;
        cin >> a;
        str[i] = a;
    }

    int mn = INT_MAX;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            mn = min(mn, static_cast<int>((str[i] ^ str[j]).count()));
        }

        if (mn == 0){
            break;
        }
    }
    
    cout << mn << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}