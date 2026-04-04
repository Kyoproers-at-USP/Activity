/*アルゴリズムと工夫点(Understory/CPU: 45 ms Memory: 5620 KB  Length: 514 B)
優先度付きキューで解く．
最大Q個の木しか扱わず，それぞれの追加と削除は最大1回しか行わない．
そのため個別に管理することができる．
優先度付きキューを用いて管理し，シミュレーションを行えば，最悪計算量は，O(Q * log2(Q)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;

int main(){
    scanf("%d", &q);
    priority_queue<int> height;
    int i, j, sum_trees = 0;
    while(q--){
        scanf("%d%d", &i, &j);
        if(i == 1)height.push(-j);
        else while(height.size() > 0 && -height.top() <= j)height.pop();
        printf("%ld\n", height.size());
    }
    return 0;
}