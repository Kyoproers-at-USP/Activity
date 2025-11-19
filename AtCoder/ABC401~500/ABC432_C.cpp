/*アルゴリズムと工夫点(Candy Tribulation/CPU: 14 ms Memory: 4316 KB  Length: 722 B)
全員に大きい飴を一旦渡してから微調整していく考え方で解く．
最悪計算量は，O(N) < 2 * 10^5
※ 一旦分布を固定してから調整していく考え方は覚えておく
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_A (1e9)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,x,y;

int main(){
    int i,j,min_a = MAX_A;
    ll min_g,ans = 0;
    scanf("%d%d%d",&n,&x,&y);
    vector<int> a(n);
    rep(i,n){
        scanf("%d",&a[i]);
        min_a = min(min_a, a[i]);
        ans += a[i];
    }
    min_g = (ll)min_a * y;
    rep(i,n){
        ll diff = (ll)y * a[i] - min_g;
        if(diff % (y - x) > 0 || diff / (y - x) > a[i]){
            puts("-1");
            return 0;
        }
        ans -= diff / (y - x);
    }
    printf("%lld\n",ans);
    return 0;
}