/*アルゴリズムと工夫点(Sake or Water/CPU: 35 ms Memory: 4748 KB  Length: 517 B)
貪欲法で解く．
最も飲める酒の量が少なくなる場合は，K杯の酒が，容量が最も小さいK杯に割り当てられていた時である．
つまり，容量が最も大きい N - K 杯が水である場合である．
この時，高橋君は「容量の大きい方から順に飲んでいく」という方針を取れば，最小のカップ数で条件を満たせる．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり，高速．
※ 高橋君自身はランダムに選択するのではなく，
※ 適切な方針を取った時の最小のカップ数を求めることに注意
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;
ll x;

int main(){
    int i, j;
    scanf("%d%d%lld", &n, &k, &x);
    vector<int> a(n);
    rep(i, n)scanf("%d", &a[i]);
    sort(a.rbegin(), a.rend());
    rep(i, k){
        x -= a[i + n - k];
        if(x <= 0)break;
    }
    printf("%d\n", x <= 0 ? i + 1 + n - k : -1);
    return 0;
}