/** Code by 1egend **/
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string x;
        cin >> n >> x;
        if (n % 2 == 0){
            bool razeWins = true;
            for (int i = 0; i < x.length(); i+= 2){
                int k = x[i] - '0';
                if (k % 2 == 0){
                    razeWins = false;
                    break;
                }
            }
            cout << (razeWins ? 1: 2) << endl;
            continue;
        }

        bool breachWins = true;
        for (int i = 0; i < x.length(); i += 2){
            int k = x[i] - '0';
            if (k % 2 == 1){
                breachWins = false;
                break;
            }
        }
        cout << (breachWins ? 2: 1) << endl;
    }
    return 0;
}
