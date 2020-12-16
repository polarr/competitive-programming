/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        if (b >= a){
            swap(a, b);
        }
        int x = 2 * b - a;
        if (x >= 0 && x % 3 == 0){
            printf("%s\n", "YES");
            continue;
        }
        printf("%s\n", "NO");
    }
    return 0;
}
