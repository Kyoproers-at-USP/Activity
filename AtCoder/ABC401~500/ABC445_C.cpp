/*アルゴリズムと工夫点(Sugoroku Destination/CPU: 69 ms Memory: 9000 KB  Length: 841 B)
BFS で解く．
各マスを頂点とし，マスからマスへの移動を有向辺で表すと，funcional graph となる．
また辺の方向も一定であるため，小さい番号のマスからBFSを始め，到達できた頂点群を同一グループとして扱い，
グループごとにスタートした時の最終到着点を求めればよい．
最悪計算量は，O(N) < 10 ^ 7 となり高速．
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
    int i, j;
    scanf("%d", &n);
    const int NIL = -1;
    vector<int> a(n), color_to_max, color(n, NIL);
    rep(i, n){
        scanf("%d", &a[i]);
        a[i]--;
    }
    auto search = [&](int now_id, int c) -> int{
        color[now_id] = c;
        while(a[now_id] != now_id){
            now_id = a[now_id];
            color[now_id] = c;
        }
        return now_id;
    };
    rep(i, n)if(color[i] == NIL){
        color_to_max.push_back(search(i, color_to_max.size()));
    }
    rep(i, n - 1)printf("%d ", color_to_max[color[i]] + 1);
    printf("%d\n", color_to_max[color[i]] + 1);
    return 0;
}