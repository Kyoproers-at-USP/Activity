/*アルゴリズムと工夫点(Upgrade Required/CPU: 46 ms Memory: 7292 KB  Length: 658 B)
各バージョンのパソコンの台数を管理して，シミュレーション．
1回の操作でバージョンがx以下のパソコンの台数は0になるため，それ以降の操作ではその個数を考慮する必要がない．
そのため最悪計算量は，O(Q + N) < 10^7 となり高速．
※ バーチャル参加
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
    const int NIL = -1;
    int i,j,zero_bd = NIL;
    scanf("%d%d",&n,&q);
    vector<int> ver_to_cnt(n,0);
    rep(i,n)ver_to_cnt[i] = 1;
    while(q--){
        int x,y,cnt = 0;
        scanf("%d%d",&x,&y);x--;y--;
        i = x;
        while(zero_bd < i){
            cnt += ver_to_cnt[i];
            i--;
        }
        ver_to_cnt[y] += cnt;
        zero_bd = max(zero_bd, x);
        printf("%d\n",cnt);
    }
    return 0;
}