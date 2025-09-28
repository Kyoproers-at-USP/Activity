/*アルゴリズムと工夫点(Find Permutation 2/CPU: 1 ms Memory: 3912 KB  Length: 736 B)
-1を適当な値で埋めて，[1,N]の順列を作ればよい．
最悪計算量は，O(N) < 10^2 となり高速．
※バーチャル参加
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define NIL -1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j;
    scanf("%d",&n);
    vector<int> a(n),cnt(n+1,0);
    rep(i,n){
        scanf("%d",&a[i]);
        if(a[i] == NIL)continue;
        cnt[a[i]]++;
        if(cnt[a[i]] > 1){
            puts("No");
            return 0;
        }
    }
    j = 1;
    rep(i,n){
        if(a[i] == NIL){
            while(j <= n && cnt[j] != 0)j++;
            a[i] = j;
            cnt[j]++;
        }
    }
    printf("Yes\n");
    rep(i,n-1)printf("%d ",a[i]);printf("%d\n",a[i]);
    return 0;
}