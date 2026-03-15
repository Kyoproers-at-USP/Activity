/*アルゴリズムと工夫点(π/CPU: 1 ms Memory: 3968 KB  Length: 297 B)
円の面積の公式を用いて解く．
*/
#include<iostream>
#include<cmath>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

double d;

int main(){
    scanf("%lf", &d);
    printf("%.7f\n", (d / 2) * (d / 2) * M_PI);
    return 0;
}