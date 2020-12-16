#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector <int> n;
        int mn = INT_MAX;
        for (int i = 0; i < x; ++i){
            int k;
            cin >> k;
            mn = min<int>(mn, k);
            n.push_back(k);
        }

        vector <int> m = n;
        sort(m.begin(), m.end());
        bool can = true;
        for (int i = 0; i < x; ++i){
            if (m[i] % mn != 0 && n[i] != m[i]){
                can = false;
                break;
            }
        }
        cout << (can ? "YES":"NO") << endl;
    }
    return 0;
}