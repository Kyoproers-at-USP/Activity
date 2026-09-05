/*アルゴリズムと工夫点(Second Half Sum/CPU: 1 ms Memory: 3760 KB  Length: 462 B)
後半の N / 2 個の値だけ上手く読み取り，その総和を求めればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;
    scanf("%d", &n);

    int ans = 0, half_n = n / 2;
    rep(i, half_n){
        int a;
        scanf("%d", &a);
    }
    rep(i, half_n){
        int a;
        scanf("%d", &a);
        ans += a;
    }

    printf("%d\n", ans);
    return 0;
}