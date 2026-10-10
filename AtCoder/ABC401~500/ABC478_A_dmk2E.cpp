/*アルゴリズムと工夫点(Grapes/CPU: 1 ms Memory: 3796 KB  Length: 354 B)
余りの計算を利用して，各人に配るぶどうの数を適切に計算すればよい．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i;

    scanf("%d%d", &n, &m);
    int base = m / n, temp = m % n;
    rep(i, n)printf("%d\n", base + (i < temp));
    return 0;
}