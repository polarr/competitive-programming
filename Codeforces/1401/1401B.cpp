#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int ans = 0;;
        if (z1 >= y2){
            ans += y2 * 2;
            z1 -= y2;
            y2 = 0;
        }
        else{
            ans += z1 * 2;
            y2 -= z1;
            z1 = 0;
        }
        ans -= max<int>(min<int>(z2 - x1 - z1, y1 - x2 - y2), 0) * 2;
        cout << ans << endl; 
    }
    return 0;
}