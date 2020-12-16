#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        int len;
        cin >> len;
        vector <int> strengths = {};
        while (len--){
            int strength;
            cin >> strength;
            strengths.push_back(strength);
        }
        // Max difference + 1
        int small = 1e3;
        for (int x = 0; x < strengths.size(); ++x){
            bool isret = false;
            for (int y = 0; y < strengths.size(); ++y){
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
        cout << small << endl;
     }
}
