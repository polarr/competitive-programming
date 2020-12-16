/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int d;
        int fit;
        for (int i = n - 1; i > 0; i --){
            if ((y - x) % i == 0){
                d = (y - x)/i;
                fit = i - 1;
                break;
            }
        }  
        int start = x - d * min<int>(floor((x-1)/d), n - 2 - fit);
        for (int i = 0; i < n; i++){
            cout << start + i * d << " ";
        }
        cout << endl;
    }
    return 0;
}
