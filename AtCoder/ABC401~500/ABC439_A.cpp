/*アルゴリズムと工夫点(2^n - 2*n/CPU: 1 ms Memory: 3892 KB  Length: 336 B)
そのまま．
べき乗演算子が実装されている言語なら実装が楽．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int ans = 0, tmp = 1;
    scanf("%d", &n);
    ans -= 2 * n;
    while(n--)tmp *= 2;
    ans += tmp;
    printf("%d\n", ans);
    return 0;
}