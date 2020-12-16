#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if (k >= n){
            cout << k - n << endl;
            continue;
        }
        if ((n - k) % 2 == 1){
            cout << 1 << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}