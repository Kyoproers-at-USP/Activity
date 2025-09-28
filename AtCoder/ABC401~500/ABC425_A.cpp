/*アルゴリズムと工夫点(Sigma Cubes/CPU: 1 ms Memory: 4060 KB  Length: 327 B)
言われた通りにやる．
べき乗が実装されている言語なら楽．
※バーチャル参加
*/
#include<iostream>
#include<cmath>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,ans = 0;
    scanf("%d",&n);
    rep(i,n)ans += pow(-1,i+1)*pow(i+1,3);
    printf("%d\n",ans);
    return 0;
}