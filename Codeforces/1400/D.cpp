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
            int z;
            cin >> z;
            n.push_back(z);
        }
        int ans = 0;
        for (int i = 0; i < n.size() - 3; ++i){
            for (int k = i + 2; k < n.size() - 1; ++k){
                if (n[i] != n[k]){
                    continue;
                }
                for (int j = i + 1; j < k; ++j){
                    for (int l = k + 1; l < n.size(); ++l){
                        if (n[j] == n[l]){
                            ans ++;
                        }
                    }                
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}