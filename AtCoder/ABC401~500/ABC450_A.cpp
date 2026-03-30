/*アルゴリズムと工夫点(3,2,1,GO/CPU: 1 ms Memory: 3860 KB  Length: 306 B)
for文使って出力する．
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
    for(i = n;i > 1;i--)printf("%d,", i);
    printf("%d\n", i);
    return 0;
}