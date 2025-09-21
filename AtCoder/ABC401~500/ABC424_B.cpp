/*アルゴリズムと工夫点(Perfect/CPU: 1 ms Memory: 3932 KB  Length: 561 B)
人ごとに何問解いたかをシミュレーションして数え上げる．
※ バーチャル参加
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;

int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> count(n,0),ans;
    while(k--){
        int a,b;
        scanf("%d%d",&a,&b);a--;b--;
        count[a]++;
        if(count[a] == m)ans.push_back(a+1);
    }
    if(ans.size() > 0){
        rep(i,ans.size()-1)printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}