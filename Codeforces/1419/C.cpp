/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l, x;
        cin >> l >> x;
        vector <int> n;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < l; i ++){
            int k;
            cin >> k;
            sum += k;
            if (k == x){
                count ++;
            }
        }
        int ans = 2;
        if (count == l){
            ans = 0;
        }
        else if (count > 0){
            ans = 1;
        }
        if (ans == 2 && sum == l * x){
            ans = 1;
        }
        cout << ans << endl;
    }
    return 0;
}
