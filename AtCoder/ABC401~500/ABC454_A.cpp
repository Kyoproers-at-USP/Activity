/*アルゴリズムと工夫点(Closed interval/CPU: 1 ms Memory: 3868 KB  Length: 268 B)
そのままやる．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int l, r;

int main(){
    scanf("%d%d", &l, &r);
    printf("%d\n", r - l + 1);
    return 0;
}