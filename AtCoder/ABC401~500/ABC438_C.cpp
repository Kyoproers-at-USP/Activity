/*アルゴリズムと工夫点(1D puyopuyo/CPU: 12 ms Memory: 4824 KB  Length: 734 B)
スタックを用いて解く．
最終的な結果は，要素を消す順序に依存しないため，先頭から4つずつ消していくことを考える．
この時，スタックを用いて実装することで，最悪計算量 O(N) で解くことができる．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define THRESH 4
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j;
    scanf("%d", &n);
    vector<int> sta;
    rep(i, n){
        int a;
        scanf("%d", &a);
        sta.push_back(a);
        if(
            sta.size() >= THRESH && 
            sta[sta.size() - 1] == sta[sta.size() - 2] && 
            sta[sta.size() - 2] == sta[sta.size() - 3] && 
            sta[sta.size() - 3] == sta[sta.size() - 4]
        ){
            j = THRESH;
            while(j--)sta.pop_back();
        }
    }
    printf("%ld\n", sta.size());
    return 0;
}