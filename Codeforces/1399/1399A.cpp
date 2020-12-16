#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        vector <int> k;
        for (int i = 0; i < l; i++){
            int z;
            cin >> z;
            k.push_back(z);
        }

        sort(k.begin(), k.end());
        int a = 0;
        for (int i = 0; i < l - 1; i++){
            if (abs(k[i] - k[i + 1]) > 1){
                a ++;
            }
        }

        if (a > 0){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }
    return 0;
}