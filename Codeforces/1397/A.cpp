#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector <int> alpha(26);
        fill(alpha.begin(), alpha.end(), 0);
        for (int i = 0; i < x; ++i){
            string z;
            cin >> z;
            for (int s = 0; s < z.length(); ++s){
                alpha[z[s] - 'a'] ++;
            }
        }
        bool can = true;
        for (int i = 0; i < 26; ++i){
            if (alpha[i] % x != 0){
                can = false;
                break;
            }
        }

        cout << (can ? "YES":"NO") << endl;
    }
    return 0;
}