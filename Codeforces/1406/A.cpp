/** Code by 1egend **/
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
            int k;
            cin >> k;
            n.push_back(k);
        }
        sort(n.begin(), n.end());

        int a = -1;
        int b = -1;
        int step = 0;
        bool alert = false;
        int count = 0;
        for (int i = 0; i < x; ++i){
            if (n[i] == count){
                step ++;
            }
            else if (n[i] == count + 1){
                if (step == 0){
                    break;
                }
                if (step > 1 && !alert){
                    a = count;
                    b = count;
                }
                else{
                    alert = true;
                    b = count;
                }
                count ++;
                step = 1;
            }
            else{
                break;
            }
        }

        if (step > 1 && !alert){
            a = count;
            b = count;
        }
        else if (step > 0){
            b = count;
        }
        cout << a + b + 2<< endl;
    }
    return 0;
}
