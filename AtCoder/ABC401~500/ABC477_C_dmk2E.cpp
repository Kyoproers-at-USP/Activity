/*アルゴリズムと工夫点(ange Search Query/CPU: 48 ms Memory: 5408 KB  Length: 894 B)
前処理 + 二分探索で解く．
S中の連続部分文字列で，Tとなるものの先頭文字の添え字 sub_t_id を前処理で求めておく．
すると各クエリでは，[L, R] 内で最も左端の sub_t_id を二分探索で高速に求め，
その連続部分文字列が，[L, R] 内に含まれているかを判定すればよい．
最悪計算量は，O(|S| * |T| + Q * log2(|S|)) < 10 ^ 7 となり，高速．
※ 問題文中の「部分文字列」の定義を「連続部分文字列」と解釈してしまい，1WA.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;
string s, t;

int main(){
    int i;

    scanf("%d", &q);
    cin >> s >> t;

    vector<int> sub_t_start_ids;
    rep(i, s.length())if(s.substr(i, t.size()) == t)sub_t_start_ids.push_back(i);

    auto judge = [&](int start, int last) -> bool{
        int min_id_of_ids = lower_bound(sub_t_start_ids.begin(), sub_t_start_ids.end(), start) - sub_t_start_ids.begin();
        return min_id_of_ids < sub_t_start_ids.size() && sub_t_start_ids[min_id_of_ids] + t.size() - 1 <= last;
    };
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%s\n", judge(/* start = */ l - 1, /* last = */ r - 1) ? "Yes" : "No");
    }
    return 0;
}