/*アルゴリズムと工夫点(On a Diet/CPU: 16 ms Memory: 4464 KB  Length: 705 B)
キューを用いてシミュレーションを行って解く．
i (∈ [1, N]) 日目のおやつを食べるか否かを，1日目から判定していく．
この時，直近最大 M - 1 日間のおやつのカロリーを時系列順に保持しておき，
その累計値がK以下であるならば，i日目のおやつを食べるようにする．
シミュレーションの途中でカロリー配列の「先頭の削除」と「末尾追加」を高速に行う必要があり，
これは「キュー」を用いれば実現できる．
最悪計算量は，O(N) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;
ll k;

int main(){
    int i;
    scanf("%d%d%lld", &n, &m, &k);
    
    queue<int> que;
    ll now_sum = 0;
    rep(i, n){
        int a;
        scanf("%d", &a);

        if(now_sum + a <= k){
            puts("Yes");
            now_sum += a;
            que.push(a);
        }else{
            puts("No");
            que.push(0);
        }

        if(que.size() == m){
            now_sum -= que.front();
            que.pop();
        }
    }
    return 0;
}