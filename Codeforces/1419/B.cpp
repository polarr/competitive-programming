/** Code by 1egend **/
#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ull x;
        cin >> x;
        int i = 1;
        ull term = 1;
        ull total = 1;
        int ans = 1;
        while(total <= x) {
            i ++;
            term = 2 * term + pow(2, 2* i - 2);
            total += term;
            ans ++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
