#include <bits/stdc++.h>

using namespace std;

void clearSame(string &a, string &b){
    for (int i = 0; i < a.length(); ++i){
        if (a[i] == b[i]){
            a.erase(a.begin() + i);
            b.erase(b.begin() + i);
            i--;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int l;
        string a;
        string b;
        cin >> l >> a >> b;
        bool broken = false;
        for (int i = 0; i < a.length(); ++i){
            if ((int)a[i] > (int)b[i]){
                cout << -1 << endl; 
                broken = true;
                break;
            }

            if (a[i] == b[i]){
                a.erase(a.begin() + i);
                b.erase(b.begin() + i);
                i--;
            }
        }

        if (broken){
            continue;
        }

        int ans = 0;
        /**
        for (char k = 'a'; k <= 't'; ++k){
            vector <int> different;
            for (int i = 0; i < l; ++i){
                if (b[i] == k && a[i] != k){
                    bool diff = true;
                    for (int z = 0; z < different.size(); z++){
                        if (a[i] == different[z]){
                            diff = false;
                            break;
                        }
                    }
                    if (diff){
                        different.push_back(a[i]);
                        ans ++;
                    }
                }
            }
        }
        **/
       while(b.length()){
           char n = a[0];
           for (int z = 0; z < a.length(); ++z){
               if(a[z] == n){
                   a[z] = b[0];
               }
           }
           ans ++;
           clearSame(a, b);
           cout << a << " " << b << endl;
       }
        cout << ans << endl;
    }
    return 0;
}