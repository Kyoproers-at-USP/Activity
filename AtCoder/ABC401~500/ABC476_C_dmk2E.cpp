/*アルゴリズムと工夫点(Third Largest Number/CPU: 52 ms Memory: 5588 KB  Length: 470 B)
3つの最大値を保持しつつ，範囲を広げていくシミュレーションで解く．
実装を楽にするため優先度付きキューを利用しているが，
最悪計算量は O(N * log2(3)) < 10 ^ 6 となり十分高速．
*/
#include<iostream>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;
    scanf("%d", &n);

    priority_queue<int> pq;
    while(n--){
        int a;
        scanf("%d", &a);

        pq.push(-a);
        if(pq.size() == 4)pq.pop();

        if(pq.size() >= 3)printf("%d\n", -pq.top());
    }
    return 0;
}