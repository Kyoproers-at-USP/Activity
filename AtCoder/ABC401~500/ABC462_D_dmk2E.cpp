/*アルゴリズムと工夫点(Accomplice/CPU: 61 ms Memory: 33048 KB  Length: 862 B)
優先度付きキュー + 時間区間を固定した全探索 で解く．
時刻 [x, x + D] の間に犯行が行われた時の有り得る2人の犯人の組を，xの昇順に求めていくことを考える．
計算には，その時間帯に館にいる犯人の数が分かればよい．
正確には時刻xの時点で館に存在し，かつ時刻 x + D より後の時刻に「館を出る」人の数を求めればよい．
これは優先度付きキューを用いて「館を出る時刻」を管理すればよい．
 1. 時刻 x に館に入る人の「館を出る時刻」をキューに入れる
 2. 時刻 [x, x + D] の間に館を出る人は，これ以降の計算では犯人候補になりえないため，キューから出す
 3. (キューに残っている要素数) = (犯人候補の数) となるため，計算
最悪計算量は，O(max(Ti) + N * log2(N)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_T (int)(1e6)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, d;

int main(){
    int i, j;

    scanf("%d%d", &n, &d);
    vector<vector<int> > time_to_exit(MAX_T + 2);
    rep(i, n){
        int s, t;
        scanf("%d%d", &s, &t);
        time_to_exit[s].push_back(t + 1);
    }

    ll ans = 0;
    priority_queue<int> min_exit;
    rep(i, MAX_T - d + 2){
        if(time_to_exit[i].size())
            for(int exit : time_to_exit[i])min_exit.push(-exit);
        
        while(min_exit.size() && i + d >= -min_exit.top())min_exit.pop();

        ll cnt = min_exit.size();
        ans += cnt * (cnt - 1) / 2;
    }

    printf("%lld\n", ans);
    return 0;
}