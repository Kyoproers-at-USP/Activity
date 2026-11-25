/*アルゴリズムと工夫点(Same Side/CPU: 1 ms Memory: 3816 KB  Length: 284 B)
A * B の符号が正の値であるかで判定すればよい．
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
    printf("%s\n", a * b >= 0 ? "Yes" : "No");
    return 0;
}