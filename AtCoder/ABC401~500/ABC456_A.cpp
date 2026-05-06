/*アルゴリズムと工夫点(Dice/CPU: 1 ms Memory: 3748 KB  Length: 282 B)
3以上18以下かを判定すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x;

int main(){
    scanf("%d", &x);
    printf("%s\n", 3 <= x && x <= 18 ? "Yes" : "No");
    return 0;
}