/*アルゴリズムと工夫点(Double-Sided Printing/CPU: 2 ms Memory: 3824 KB  Length: 261 B)
N を 2 で割った値の切り上げが解となる．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    scanf("%d", &n);
    printf("%d\n", (n + 1) / 2);
    return 0;
}