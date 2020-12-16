#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;
        vector <int> n;
        for (int i = 0; i < x; ++i){
            int s;
            cin >> s;
            n.push_back(s);
        }
        unsigned long long ans = 0;
        for (int i = x - 1; i > 0; --i){
            if (n[i] < n[i - 1]){
                ans += n[i - 1] - n[i];
            }
        }

        cout << ans << endl;
    }
    return 0;
}