#include<bits/stdc++.h>

// Accidentally edited 1360B on this :p
// What a bad start XD lul

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        int len;
        cin >> len;
        int strengths[len] = {};
        while (len--){
            int strength;
            cin >> strength;
            strengths.append(strength);
        }
        // Max difference + 1
        int small = 1e3;
        for (int x = 0; x < strengths.length(); ++x){
            bool isret = false;
            for (int y = 0; y < strengths.length(); ++y){
                if (x == y){
                    continue;
                }
                int diff = abs(strengths[x] - strengths[y]);
                if (diff == 0){
                    small = 0;
                    isret = true;
                    break;
                }
                if (diff < small){
                    small = diff;
                }
            }
            if (isret){
                break;
            }
        }
        cout << small;
     }
}
