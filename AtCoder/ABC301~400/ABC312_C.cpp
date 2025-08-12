/*アルゴリズムと工夫点(Invisible Hand/CPU: 67 ms Memory: 4920 KB  Length: 838 B)
二分探索で解く．
最悪計算量は，O(N+M+log2(max(Ai,Bi))*(log2(N)+log2(M)))<10^6 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_AB ((int)(1e9)+1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    vector<int> a(n),b(m);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,m)scanf("%d",&b[i]);
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    int left=0,right=MAX_AB+1;
    auto judge=[&](int x)->bool{
        int a_cnt=lower_bound(a.begin(),a.end(),x+1)-a.begin();
        int b_cnt=b.end()-lower_bound(b.begin(),b.end(),x);
        return a_cnt>=b_cnt;
    };
    while(left<right){
        int mid=(left+right)/2;
        if(judge(mid))right=mid;
        else left=mid+1;
    }
    printf("%d\n",left);
    return 0;
}