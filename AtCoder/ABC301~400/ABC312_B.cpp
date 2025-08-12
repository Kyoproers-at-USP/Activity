/*アルゴリズムと工夫点(TaK Code/CPU: 2 ms Memory: 3912 KB  Length: 1028 B)
そのままやる．
実装が重いので，ミスのないよう気を付けよう．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define H 9
#define W 9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> P;

int n,m;

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    vector<string> ipt(n);
    vector<P> ans;
    rep(i,n)cin>>ipt[i];
    const int dy[]={3,3,3,0,1,2,3,5,5,5,5,6,7,8},MAX_D=14;
    const int dx[]={0,1,2,3,3,3,3,5,6,7,8,5,5,5};
    auto judge=[&](int sy,int sx)->bool{
        int i,j;
        rep(i,3)rep(j,3)if(ipt[sy+i][sx+j]=='.')return false;
        rep(i,3)rep(j,3)if(ipt[sy+6+i][sx+6+j]=='.')return false;
        rep(i,MAX_D){
            int y=sy+dy[i];
            int x=sx+dx[i];
            if(ipt[y][x]=='#')return false;
        }
        return true;
    };
    for(i=0;i+H-1<n;i++)for(j=0;j+W-1<m;j++){
        if(judge(i,j))ans.push_back(P(i,j));
    }
    rep(i,ans.size())printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    return 0;
}