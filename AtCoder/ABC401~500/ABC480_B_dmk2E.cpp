/*アルゴリズムと工夫点(Invalid Vote/CPU: 1 ms Memory: 3896 KB  Length: 1136 B)
M 個の投票用紙に書かれた名前一つ一つを固定し， N 人のいずれかの有効な一票となるか全探索して解く．
最悪計算量は，O(N * M * max(S_{i}, T_{i})) < 10 ^ 6 となり，十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

bool judge(const string& str1, const string& str2){
    int i, cnt = 0;

    rep(i, str1.length())cnt += str1[i] != str2[i];
    return cnt == 1;
}

int main(){
    int i, j;

    scanf("%d%d", &n, &m);
    vector<string> names(n);
    rep(i, n)cin >> names[i];

    const int NIL = -1;
    auto calc = [&](string str) -> int{
        int i;
        
        rep(i, n)if(names[i] == str)return i;

        int ans_id = NIL;
        rep(i, n)if(
            names[i].length() == str.length() &&
            judge(/* str1 = */ names[i], /* str2 = */ str)
        ){
            if(ans_id != NIL)return NIL;
            ans_id = i;
        }

        return ans_id;
    };
    vector<int> ans(n, 0);
    while(m--){
        string t;
        cin >> t;

        int names_id = calc(/* str = */ t);
        if(names_id != NIL)ans[names_id]++;
    }

    rep(i, n)printf("%d\n", ans[i]);
    return 0;
}