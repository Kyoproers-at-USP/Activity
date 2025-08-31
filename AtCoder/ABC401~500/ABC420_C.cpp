/*アルゴリズムと工夫点(Sum of Min Query/CPU: 96 ms Memory: 5220 KB  Length: 813 B)
差分に着目してシミュレーション．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,q;

int main(){
    int i,j;
    ll sum=0;
    scanf("%d%d",&n,&q);
    vector<int> a(n),b(n);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,n)scanf("%d",&b[i]);
    rep(i,n)sum+=min(a[i],b[i]);
    while(q--){
        getchar();
        char c=getchar();
        int x,v;
        scanf("%d%d",&x,&v);
        if(c=='A'){
            x--;
            sum-=min(a[x],b[x]);
            a[x]=v;
            sum+=min(a[x],b[x]);
        }else{
            x--;
            sum-=min(a[x],b[x]);
            b[x]=v;
            sum+=min(a[x],b[x]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}