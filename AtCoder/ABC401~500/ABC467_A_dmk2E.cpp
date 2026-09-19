/*アルゴリズムと工夫点(Obesity/CPU: 1 ms Memory: 3696 KB  Length: 297 B)
単位に気を付けつつ，割り算の形を排除した条件式で判定する．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w;

int main(){
    scanf("%d%d", &h, &w);
    printf("%s\n", w * 10000 >= 25 * h * h ? "Yes" : "No");
    return 0;
}