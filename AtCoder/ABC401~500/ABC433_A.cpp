/*アルゴリズムと工夫点(Happy Birthday! 4/CPU: 2 ms Memory: 3876 KB  Length: 314 B)
式変形して，適切な条件判定をする．
「x + k = (y + k) * z」を満たす負でない整数kが存在すればよい．
式変形より，k = (x - y * z) / (z - 1) であるから，この形から条件を立てる．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x,y,z;

int main(){
    scanf("%d%d%d",&x,&y,&z);
    printf("%s\n", x >= y * z && (x - y * z ) % (z - 1) == 0 ? "Yes" : "No");
    return 0;
}