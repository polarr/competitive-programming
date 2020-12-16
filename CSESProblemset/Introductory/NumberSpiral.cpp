#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int y, x;
        cin >> y >> x;
        unsigned long long maxs = max <int> (x, y) - 1;
        if (maxs%2 == 0){
            cout << maxs * maxs + x + maxs + 1 - y << endl;
            continue;
        }
        cout << maxs * maxs + y + maxs + 1 - x << endl;
    }
    return 0;
}