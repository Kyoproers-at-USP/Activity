/*アルゴリズムと工夫点(Change Schools/CPU: 13 ms Memory: 5168 KB  Length: 654 B)
頻度表を作って解を求める．
1クラスに含まれる最大人数 M とすると，解は
（人数がMのクラス数） + （人数が M - 1 のクラス数）となる．
従って，まずクラスごとの人数を求め，
その後人数毎のクラスの数の頻度表を作り，解を出力する．
最悪計算量は，O(N + K) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;

int main(){
    int i;

    scanf("%d%d", &n, &k);
    vector<int> class_num(k, 0);
    int max_class_num = 0;
    rep(i, n){
        int a;
        scanf("%d", &a);

        class_num[a - 1]++;
        max_class_num = max(max_class_num, class_num[a - 1]);
    }

    vector<int> num_to_cnt(n + 1, 0);
    rep(i, k)num_to_cnt[class_num[i]]++;

    printf("%d\n", num_to_cnt[max_class_num] + num_to_cnt[max_class_num - 1]);
    return 0;
}