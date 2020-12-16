#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector <vector <int>> students(n);
        vector <int> gonetime(n);
        vector <int> queue;
        for (int i = 0; i < n; i++){
            int a; 
            int b;
            cin >> a >> b;
            students[i].push_back(a);
            students[i].push_back(b);
        }

        int gone = 0;
        int s = 1;
        while(gone < students.size()){
            // students come
            for (int i = 0; i < students.size(); ++i){
                if (students[i][0] == s){
                    queue.push_back(i);
                }
            }

            // remove impatient students
            for (int i = 1; i < queue.size(); ++i){
                if (students[queue[i]][1] == s){
                    gonetime[queue[i]] = 0;
                    queue.erase(queue.begin() + i);
                    gone ++;
                    --i;
                }
            }

            // first guy takes his
            if (queue.size() > 0){
                gonetime[queue[0]] = s;
                queue.erase(queue.begin() + 0);
                gone ++;
            }

            // next second
            s++;
        }

        for (int i = 0; i < gonetime.size(); i++){
            cout << gonetime[i] << " ";
        }
        cout << endl;
    }
    return 0;
}