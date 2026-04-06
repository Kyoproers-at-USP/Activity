/*アルゴリズムと工夫点(Gothec/CPU: 1 ms Memory: 3832 KB  Length: 442 B)
そのままやる．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int m, d;

int main(){
    scanf("%d%d", &m, &d);
    if(
        (m == 1 && d == 7) || 
        (m == 3 && d == 3) || 
        (m == 5 && d == 5) || 
        (m == 7 && d == 7) || 
        (m == 9 && d == 9)
    )puts("Yes");
    else puts("No");
    return 0;
}