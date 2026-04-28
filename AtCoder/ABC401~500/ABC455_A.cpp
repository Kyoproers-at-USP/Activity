/*アルゴリズムと工夫点(455/CPU: 1 ms Memory: 3756 KB  Length: 299 B)
論理演算を利用して解く．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a, b, c;

int main(){
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", a != b && b == c ? "Yes" : "No");
    return 0;
}