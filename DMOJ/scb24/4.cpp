/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-28
 * Contest: DMOJ Spring Coding Bowl 2024
 * Problem: 4
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    unordered_map<bitset<25>, int> exam;

    for (int i = 0; i < n; i++){
        bitset<25> a;
        cin >> a;
        exam[a]++;
    }

    int ans = 0;
    bitset<25> mask = bitset<25>((1 << m) - 1);
    for (int i = 0; i < (1 << m); i++){
        int cnt = 0;
        bitset<25> x = bitset<25>(i);
        for (int j = 0; j < (1 << m); j++){
            bitset<25> y = bitset<25>(j);
            if (static_cast<int>((~(x ^ y) & mask).count()) >= k){
                cnt+= exam[y];
            }
        }

        ans = max(cnt, ans);
    }
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}