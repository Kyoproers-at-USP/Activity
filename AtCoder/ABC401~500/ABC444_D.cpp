/*アルゴリズムと工夫点(Many Repunit Sum/CPU: 22 ms Memory: 5792 KB  Length: 912 B)
imos法で解く．
最終的な解は天文学的数値のため，配列ansで保持して置く．
1をAiだけ繋げた数を加算するということは，ans[0, Ai - 1] に1加算するということである．
従って，N個のAiに対応した区間加算を，imos法で実装することで高速化する．
加算が終わった後は，最下桁から桁の繰り上げ計算を行う．
最悪計算量は，O(N) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, max_a = 0;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n){
        scanf("%d", &a[i]);
        max_a = max(max_a, a[i]);
    }
    vector<int> ans(max_a + 1);
    rep(i, n){
        ans[0]++;ans[a[i]]--;
    }
    rep(i, max_a)ans[i + 1] += ans[i];
    rep(i, max_a){
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while(ans[max_a] > 10){
        ans.push_back(ans[max_a] / 10);
        ans[max_a] %= 10;
        max_a++;
    }
    i = 0;
    while(ans[ans.size() - 1 - i] == 0)i++;
    while(i < ans.size() - 1){
        printf("%d", ans[ans.size() - 1 - i]);
        i++;
    }
    printf("%d\n", ans[ans.size() - 1 - i]);
    return 0;
}