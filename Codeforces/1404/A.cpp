/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long a, b;
        cin >> a >> b;
        cout << fixed << int(ceil(llabs(a - b)/10.0)) << endl;
    }
    return 0;
}
