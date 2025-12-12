/*アルゴリズムと工夫点(Domino/CPU: 27 ms Memory: 5728 KB  Length: 652 B)
シミュレーションで解く．
倒されるドミノの座標と，今現在訪問中の座標を保持すれば，最悪計算量O(N)となる．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j,ans = 0;
    scanf("%d",&n);
    vector<int> a(n);
    rep(i,n)scanf("%d",&a[i]);
    int max_range = a[0];
    i = 0;
    while(i < n){
        int nxt_max = max_range;
        while(i < n && i < max_range){
            ans++;
            nxt_max = max(nxt_max, i + a[i]);
            i++;
        }
        if(nxt_max == max_range)break;
        swap(max_range, nxt_max);
    }
    printf("%d\n", ans);
    return 0;
}