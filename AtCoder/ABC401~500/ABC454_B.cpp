/*アルゴリズムと工夫点(Mapping/CPU: 1 ms Memory: 3976 KB  Length: 742 B)
服毎の，その服を着ている人数を配列で保持しておき，各質問に対する解を求めればよい．
最悪計算量は，O(N + M) < 10 ^ 3 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    vector<int> clothe_to_cnt(m, 0);
    rep(i, n){
        int f;
        scanf("%d", &f);
        clothe_to_cnt[f - 1]++;
    }

    bool is_all_different = false;
    rep(i, m)if(clothe_to_cnt[i] > 1)break;
    is_all_different = i == m;

    bool is_all_more_one = false;
    rep(i, m)if(clothe_to_cnt[i] < 1)break;
    is_all_more_one = i == m;

    printf("%s\n", is_all_different ? "Yes" : "No");
    printf("%s\n", is_all_more_one ? "Yes" : "No");
    return 0;
}