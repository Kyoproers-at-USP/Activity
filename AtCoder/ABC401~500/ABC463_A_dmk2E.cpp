/*アルゴリズムと工夫点(16:9/CPU: 1 ms Memory: 3824 KB  Length: 289 B)
16 * Y = 9 * X を満たすかを判定すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x, y;

int main(){
    scanf("%d%d", &x, &y);
    printf("%s\n", 16 * y == 9 * x ? "Yes" : "No");
    return 0;
}