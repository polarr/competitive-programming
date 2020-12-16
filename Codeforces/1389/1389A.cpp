#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        int b;
        cin >> a >> b;

        if (b < a * 2){
            cout << "-1 " << "-1 " << endl;
            continue;
        }

        cout << a << " " << 2 * a << endl;
    }
    return 0;
}