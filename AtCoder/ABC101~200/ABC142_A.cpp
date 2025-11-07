/*アルゴリズムと工夫点(Odds of Oddness/CPU: 1 ms Memory: 3900 KB  Length: 269 B)
偶数と奇数の数を求めて，解を計算する．
※ 整数型同士の割り算は小数点切り捨てになることを利用している．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    scanf("%d",&n);
    printf("%.7f\n", (double)(n - n / 2) / n);
    return 0;
}