/*アルゴリズムと工夫点(Second Choice Election/CPU: 115 ms Memory: 17536 KB  Length: 1621 B)
ソート + 当選する可能性がある候補者の票数にのみ着目して解く．
まず，投票者全員第一希望に入れた状態を元に考える．
この時，各候補者1 ~ Nが辞退するケースを順に考えても，票の移動回数は M 回となる．
そしてこの票の移動先の候補者群と，票の移動前に最も得票数が多かった候補者一人の中から，
得票数が最大の候補者の番号を出力すればよい．
最悪計算量は，O(N * log2(N) + M) < 10 ^ 7 となり，高速．
※ 票の移動の際，元に戻す処理を入れることで，実装を楽にしている
※ 得票数が同じ場合，番号が最小の候補者が優先されることに注意
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

class Candidate{
public:
    int num;
    vector<int> bs;

    Candidate(int num = 0):num(num){}

    bool operator<(const Candidate& k)const{
        return this -> bs.size() < k.bs.size() || 
               (this -> bs.size() == k.bs.size() && this -> num > k.num);
    }

    void addVote(int b){
        this -> bs.push_back(b);
    }
};

typedef pair<int, int> P; // (votes, num)

int n, m;

int main(){
    int i;

    scanf("%d%d", &n, &m);
    vector<Candidate> cs(n);
    rep(i, n)cs[i].num = i;
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;

        cs[a].addVote(/* b = */ b);
    }

    sort(cs.rbegin(), cs.rend());
    vector<int> num_to_sorted_id(n);
    rep(i, n)num_to_sorted_id[cs[i].num] = i;

    rep(i, n){
        int target_id = num_to_sorted_id[i];

        for(int b : cs[target_id].bs)cs[num_to_sorted_id[b]].bs.push_back(0);

        P max_cand = target_id == 0 ? 
                     P(cs[1].bs.size(), -cs[1].num) : 
                     P(cs[0].bs.size(), -cs[0].num);
        for(int b : cs[target_id].bs){
            max_cand = max(max_cand, P(
                cs[num_to_sorted_id[b]].bs.size(), 
                -b
            ));
        }

        for(int b : cs[target_id].bs)cs[num_to_sorted_id[b]].bs.pop_back();

        printf("%d\n", -max_cand.second + 1);
    }
    return 0;
}