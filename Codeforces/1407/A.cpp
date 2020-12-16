/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

void printAns(vector <int> arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
}
int main(){
    int t;
    cin >> t;        
    while(t--){
        int l;
        cin >> l;
        vector <int> x;
        int oddSum = 0;
        int evenSum = 0;
        for (int i = 0; i < l; ++i){
            int k;
            cin >> k;
            x.push_back(k);
            if (k % 2 == 0){
                evenSum += k;
            }
            else{
                oddSum += k;
            }
        } 
        int diff = abs(evenSum - oddSum);
        int greater = evenSum > oddSum ? 0:1;
        if (diff % 2 == 1){
            for (int i = 0; i < l; ++i){
                if (x[i] == 0){
                    if (i % 2 == 0){
                        greater = greater == 0 ?1:0;
                    }
                    x.erase(x.begin() + i);
                    break;
                }
            }
        }
        int s = 0;
        for (int i = greater; i < l; i += 2){
            if (x[i] == 1){
                x.erase(x.begin() + i);
                s ++;
                i --;
            }
            if (s == diff){
                printAns(x);
                cout << "hey";
                return 0;
            }
        }
    }
    return 0;
}
