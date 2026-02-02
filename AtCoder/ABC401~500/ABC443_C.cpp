/*アルゴリズムと工夫点(Chokutter Addiction/CPU: 17 ms Memory: 4812 KB  Length: 693 B)
キューを用いてシミュレーション．
高橋君がchokutterを開いた時刻と，青木君が高橋君のデスクの後ろを通る時刻を管理してシミュレーションして解く．
最悪計算量は，O(N) < 10 ^ 6 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, t;

int main(){
    const int INTERVAL = 100;
    int i, last_t, ans = 0;
    scanf("%d%d", &n, &t);
    queue<int> a;
    rep(i, n){
        int tmp;
        scanf("%d", &tmp);
        a.push(tmp);
    }
    last_t = 0;
    while(a.size()){
        if(last_t < a.front()){
            ans += a.front() - last_t;
            last_t = a.front() + INTERVAL;
        }
        a.pop();
    }
    if(last_t <= t)ans += t - last_t;
    printf("%d\n", ans);
    return 0;
}