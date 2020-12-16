/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        string x;
        cin >> x;
        int ans = 0;
        for (int i = 0; i < x.length(); ++i){
            int len = 0;
            int sum = x[0];
            while(len < x.length() - 1){
                int temp;
                for (int i = len;)
                if (len == sum){
                    ans ++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
