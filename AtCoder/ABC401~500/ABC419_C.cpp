/*アルゴリズムと工夫点(King's Summit/CPU: 46 ms Memory: 4872 KB  Length: 590 B)
貪欲法．
max(ceil(x座標の範囲/2),ceil(y座標の範囲/2)) が解となる．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j,min_r=(2e9),max_r=0,max_c=0,min_c=(2e9);
    scanf("%d",&n);
    vector<int> r(n),c(n);
    rep(i,n){
        scanf("%d%d",&r[i],&c[i]);
        min_r=min(min_r,r[i]);
        min_c=min(min_c,c[i]);
        max_r=max(max_r,r[i]);
        max_c=max(max_c,c[i]);
    }
    printf("%d\n",max((max_c-min_c+1)/2,(max_r-min_r+1)/2));
    return 0;
}