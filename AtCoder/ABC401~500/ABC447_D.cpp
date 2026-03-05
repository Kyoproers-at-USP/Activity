/*アルゴリズムと工夫点(Take ABC 2/CPU: 21 ms Memory: 8844 KB  Length: 948 B)
貪欲法で解く．
できるだけ先頭のものから，A → B → Cの順に選んでいくと，最大回数だけ操作を行うことができる．
そのため，'A', 'B', 'C' それぞれについて |S| 上の添え字をキューで管理し，シミュレーションを行えばよい．
最悪計算量は，O(|S|) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_ALFA 3
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    int i, j;
    cin >> s;
    vector<queue<int> > alfa_to_que(MAX_ALFA);
    rep(i, s.length()){
        int id = s[i] - 'A';
        alfa_to_que[id].push(i);
    }
    auto calc = [&]() -> int{
        int ans = 0;
        const int NIL = -1;
        while(1){
            int last_id = NIL;
            rep(i, MAX_ALFA){
                while(alfa_to_que[i].size() && last_id > alfa_to_que[i].front())alfa_to_que[i].pop();
                if(!alfa_to_que[i].size())return ans;
                last_id = alfa_to_que[i].front();
                alfa_to_que[i].pop();
            }
            ans++;
        }
        return NIL;
    };
    printf("%d\n", calc());
    return 0;
}