/*アルゴリズムと工夫点(Minimize Range/CPU: 28 ms Memory: 5284 KB  Length: 697 B)
ソート + キュー で解く．
Aの各要素は，K の値をいくつ足してもKで割った余りは同じである．
（以下，MOD K で考える）
そこでKずつ区切った軸上に，Aの各要素に任意の回数だけKを加算した位置に点を配置してみる．
すると，Aの各要素間の大小関係は，大きさKの区間でループする構造を取っている．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;

int main(){
    int i, j;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    rep(i, n){
        scanf("%d", &j);
        a[i] = j % k;
    }
    sort(a.begin(), a.end());
    queue<int> que;
    rep(i, n)que.push(a[i]);

    int ans = a.back() - a.front();
    rep(i, n){
        ans = min(ans, que.back() - que.front());
        int min_a = que.front();que.pop();
        que.push(min_a + k);
    }
    printf("%d\n", ans);
    return 0;
}