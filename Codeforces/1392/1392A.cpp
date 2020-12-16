#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if (x == 1){
            cin >> x;
            cout << 1 << endl;
            continue;
        }
        int past;
        cin >> past;
        int curr;

        bool a = false;
        for (int i = 1; i < x; ++i){
            cin >> curr;
            if (curr != past){
                a = true;
            }
            past = curr;
        }
        if (a){
            cout << 1 << endl;
            continue;
        }
        cout << x << endl;
    }
    return 0;
}