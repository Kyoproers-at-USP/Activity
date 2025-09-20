/*アルゴリズムと工夫点(Scary Fee/CPU: 1 ms Memory: 3908 KB  Length: 497 B)
X - m - floor(m/1000)*c >= 0 を満たす最大のmを求めればよい．
これは二分探索を用いて，最悪計算量は，O(log2(N)) < 10^2 で求められる．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define BASE 1000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x,c;

int main(){
    ll left, right, mid;
    scanf("%d%d",&x,&c);
    left = 0;right = x + 1;
    while(left < right){
        mid = (left + right) / 2;
        if(x - BASE * mid - mid * c >= 0)left = mid + 1;
        else right = mid;
    }
    printf("%lld\n", BASE * (left - 1));
    return 0;
}