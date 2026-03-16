/*アルゴリズムと工夫点(Except and Min/CPU: 673 ms Memory: 18820 KB  Length: 852 B)
map を用いてシミュレーションを行う．
ボールに書かれた整数毎の個数を連想配列で保持して置く．
配列Bの長さは最大5であるため，各クエリ毎に削除処理を行ってもそこまで処理は重くならない．
最悪計算量は，O(N + Q * (K * log2(N))) < 10 ^ 8 となり間に合う．
*/
#include<iostream>
#include<vector>
#include<map>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, q;

int main(){
    int i, j;
    scanf("%d%d", &n, &q);
    vector<int> id_to_a(n);
    map<int, int> a_to_cnt;
    rep(i, n){
        int a;
        scanf("%d", &a);
        id_to_a[i] = a;
        a_to_cnt[a]++;
    }
    while(q--){
        int k;
        scanf("%d", &k);
        vector<int> b(k);
        rep(i, k){
            scanf("%d", &b[i]);b[i]--;
            a_to_cnt[id_to_a[b[i]]]--;
        }
        for(auto [a, cnt] : a_to_cnt){
            if(cnt > 0){
                printf("%d\n", a);
                break;
            }
        }
        rep(i, k)a_to_cnt[id_to_a[b[i]]]++;
    }
    return 0;
}