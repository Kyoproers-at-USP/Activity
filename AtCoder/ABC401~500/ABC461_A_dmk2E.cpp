/*アルゴリズムと工夫点(Armor/CPU: 1 ms Memory: 3872 KB  Length: 280 B)
そのままやる．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int d, a;

int main(){
    scanf("%d%d", &a, &d);
    printf("%s\n", a <= d ? "Yes" : "No");
    return 0;
}