/*アルゴリズムと工夫点(Train Reservation/CPU: 2 ms Memory: 3768 KB  Length: 486 B)
X列目が明いている列車があるかどうかに着目すればよい．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
char x;

int main(){
    int i, j;
    
    scanf("%d %c", &n, &x);
    int col_id = x - 'A';

    rep(i, n){
        string str;
        cin >> str;
        if(str[col_id] == 'o'){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}