/*アルゴリズムと工夫点(2x2 Placing/CPU: 374 ms Memory: 41360 KB  Length: 818 B)
setを用いて解く．
ブロックを置いた座標のみを管理して，毎回ブロックを置けるかの判定を繰り返せばよい．
最悪計算量は，O(M * log2(M)) < 10^7 となり高速．
*/
#include<iostream>
#include<set>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> P;

int n,m;

int main(){
    int i,j,ans = 0;
    scanf("%d%d",&n,&m);
    set<P> v;
    auto judge = [&](int r,int c) -> bool{
        int i,j;
        rep(i,2)rep(j,2){
            int y = r + i;
            int x = c + j;
            if(0 > y || y >= n || 0 > x || x >= n || v.find(P(y, x)) != v.end())return false;
        }
        return true;
    };
    while(m--){
        int r,c;
        scanf("%d%d",&r,&c);
        r--;c--;
        if(judge(r, c)){
            ans++;
            rep(i,2)rep(j,2)v.insert(P(r + i, c + j));
        }
    }
    printf("%d\n", ans);
    return 0;
}