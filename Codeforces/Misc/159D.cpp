/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    string x;
    cin >> x;
    int n = x.length();
    int ans = 0;
    for (float a = 0; a < n - 1; a += 0.5){
        for (float b = a + (a - (int)a == 0 ? 1: 1.5); b < n; b += 0.5){
            int aL = ceil(a - 0.5);
            int aR = floor(a + 0.5);
            int bL = ceil(b - 0.5);
            int bR = floor(b + 0.5);
            int al = aL;
            int ar = aR;
            while (al >= 0 && ar < bL && x[al] == x[ar]){
                int bl = bL;
                int br = bR;
                while(bl > ar && br < n  && x[bl] == x[br]){
                    bl --;
                    br ++;
                    ans ++;
                }
                al --;
                ar ++;
            }
        }
    }
    cout << ans;
    return 0;
}
