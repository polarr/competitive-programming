#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        unsigned long long k;
        cin >> n >> k;
        vector <int> p;
        int mx = -1e10;
        int mn = 1e10;
        for (int i = 0; i < n; ++i){
            int s;
            cin >> s;
            mx = max<int>(mx, s);
            mn = min<int>(mn, s);
            p.push_back(s);
        }
        for (int i = 0; i < n; ++i){
            p[i] = mx - p[i];
            if (k % 2 == 1){
                cout << p[i] << " ";
                continue;
            }

            cout << mx - mn - p[i] << " ";
        }

        cout << endl;
    }
    return 0;
}