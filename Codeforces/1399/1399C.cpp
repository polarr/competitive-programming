#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector <int> k;
        for (int i = 0; i < x; i++){
            int z;
            cin >> z;
            k.push_back(z);
        }

        sort(k.begin(), k.end());
        int ans = 0;
        for (int i = k[0] + k[1]; i <= k[k.size() - 2] + k[k.size() - 1]; i++){
            for(int z = 0; z < k.size(); z++){
            
            }
        }
    }
    return 0;
}