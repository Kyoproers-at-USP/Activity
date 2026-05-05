/*アルゴリズムと工夫点(Vanish/CPU: 52 ms Memory: 8928 KB  Length: 804 B)
ソート + 優先度付きキューを用いて解く．
配列A をその値毎にグルーピングし，各グループの総和の配列を考える．
この時，上位 K 位の値の総和 sum_k が，小さくすることができる最大の値となるため，
配列A の総和から，sum_k を引いたものが解となる．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり，高速．
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
    ll ans = 0;
    rep(i, n){
        scanf("%d", &a[i]);
        ans += a[i];
    }

    sort(a.begin(), a.end());
    priority_queue<ll> pq;
    i = 0;
    while(i < n){
        int val = a[i];
        ll sum = 0;
        while(i < n && val == a[i]){
            sum += a[i];
            i++;
        }
        pq.push(sum);
    }

    while(k > 0 && pq.size() > 0){
        ans -= pq.top();pq.pop();
        k--;
    }
    printf("%lld\n", ans);
    return 0;
}