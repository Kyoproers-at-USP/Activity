/*アルゴリズムと工夫点(chmin/CPU: 3 ms Memory: 3912 KB  Length: 401 B)
シミュレーションして解く．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, x;

int main(){
    int i, a;
    scanf("%d%d", &n, &x);
    rep(i, n){
        scanf("%d", &a);
        if(a < x){
            x = a;
            printf("%d\n", 1);
        }else printf("%d\n", 0);
    }
    return 0;
}