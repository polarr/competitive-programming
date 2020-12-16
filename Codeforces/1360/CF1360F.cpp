#include <bits/stdc++.h>

using namespace std;

int solve(){
    int much, len;
    cin >> much >> len;
    vector <string> words(much);
    for (int i = 0; i < much; i++){
        cin >> words[i];
    }

    string solution = words[0];
    for (int i = 0; i < len; i++){
        char save = solution [i];
        bool wrong = false;
        for (char t = 'a'; t <= 'z'; ++t){
            solution[i] = t;
            wrong = false;
            for (int x = 0; x < much; x++){
                int error = 0;
                for (int z = 0; z < len; z++){
                    if (solution[z] != words[x][z]){
                        error ++;
                    }

                    if (error > 1){
                        wrong = true;
                        break;
                    }
                }

                if (wrong){
                    break;
                }
            }

            if (!wrong){
                cout << solution << endl;
                return 1;
            }
        }
        solution[i] = save;
    }
    cout << "-1" << endl;
}
int main(){
    int cases;
    cin >> cases;
    while (cases--){
        solve();
    }
}
