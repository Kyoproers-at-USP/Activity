/*アルゴリズムと工夫点(Supermajority/CPU: 1 ms Memory: 3764 KB  Length: 287 B)
式変形により，商を含まない形に変形すると，浮動小数点型による誤差を考えなくて済むので楽．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a, b;

int main(){
    scanf("%d%d", &a, &b);
    printf("%s\n", 3 * a > b * 2 ? "Yes" : "No");
    return 0;
}
