/*アルゴリズムと工夫点(Omelette Restaurant/CPU: 48 ms Memory: 5756 KB  Length: 1037 B)
キューを使って解く．
卵は仕入れ日と個数をセットにして管理し，卵の仕入れ・使用・処分をシミュレーションする．
日付順にシミュレーションを行うため，卵の情報はキューを用いて管理すれば，仕入れ日の昇順に卵を取り出せる．
1テストケース当たりの最悪計算量は，O(N) < 10 ^ 6 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// (仕入れ日, 個数)
typedef pair<int, int> P;

int t;

int solve(){
    int i, n, d;
    scanf("%d%d", &n, &d);
    vector<int> a(n);
    queue<P> eggs;
    rep(i, n)scanf("%d", &a[i]);
    rep(i, n){
        eggs.push(P(i, a[i]));
        int b;
        scanf("%d", &b);
        while(b > 0){
            if(eggs.front().second < b){
                b -= eggs.front().second;
                eggs.pop();
            }else{
                eggs.front().second -= b;
                b = 0;
            }
        }
        while(eggs.size() && eggs.front().first + d <= i)eggs.pop();
    }
    int ans = 0;
    while(eggs.size()){
        ans += eggs.front().second;
        eggs.pop();
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    while(t--)printf("%d\n", solve());
    return 0;
}