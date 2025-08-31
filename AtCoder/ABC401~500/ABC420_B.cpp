/*アルゴリズムと工夫点(Most Minority/CPU: 1 ms Memory: 3872 KB  Length: 862 B)
そのまま．
実装が少し重め．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i,j,max_p=0;
    scanf("%d%d",&n,&m);
    vector<string> s(n);
    vector<int> id_to_point(n,0);
    rep(i,n)cin>>s[i];
    rep(j,m){
        int x=0,y=0;
        rep(i,n)x+=s[i][j]=='0',y+=s[i][j]=='1';
        if(x==0||y==0)rep(i,n)id_to_point[i]++;
        else if(x<y){
            rep(i,n)if(s[i][j]=='0')id_to_point[i]++;
        }else{
            rep(i,n)if(s[i][j]=='1')id_to_point[i]++;
        }
        rep(i,n)max_p=max(max_p,id_to_point[i]);
    }
    vector<int> ans;
    rep(i,n)if(id_to_point[i]==max_p)ans.push_back(i);
    rep(i,ans.size()-1)printf("%d ",ans[i]+1);
    printf("%d\n",ans[i]+1);
    return 0;
}