/*アルゴリズムと工夫点(Odd Index Sum/CPU: 1 ms Memory: 3844 KB  Length: 390 B)
言われた通りに集計する．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, ans = 0;
    
    scanf("%d", &n);
    rep(i, n){
        int a;
        scanf("%d", &a);
        
        if(i % 2 == 0)ans += a;
    }

    printf("%d\n", ans);
    return 0;
}