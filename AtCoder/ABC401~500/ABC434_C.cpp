/*アルゴリズムと工夫点(Flapping Takahashi/CPU: 25 ms Memory: 3868 KB  Length: 799 B)
高橋君の存在しうる区間を保持しながらシミュレーション．
最悪計算量は，O(T * N) < 10^6 となり十分高速．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int t;

bool solve(){
    int i,j,n,h,now_t = 0, flag = true;
    ll mn_h, mx_h;
    scanf("%d%d",&n,&h);
    mn_h = mx_h = h;
    rep(i,n){
        int t,mn,mx;
        scanf("%d%d%d",&t,&mn,&mx);
        if(flag){
            ll now_mn = mn_h - abs(now_t - t),now_mx = mx_h + abs(now_t - t);
            ll nxt_mn = max(now_mn, (ll)mn),nxt_mx = min(now_mx, (ll)mx);
            if(nxt_mn > nxt_mx)flag = false;
            swap(mn_h, nxt_mn);swap(mx_h, nxt_mx);swap(now_t,t);
        }
    }
    return flag;
}

int main(){
    scanf("%d",&t);
    while(t--)printf("%s\n",solve() ? "Yes" : "No");
    return 0;
}