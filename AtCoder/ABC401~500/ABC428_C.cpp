/*アルゴリズムと工夫点(Brackets Stack Query/CPU: 113 ms Memory: 4328 KB  Length: 847 B)
シミュレーションで解く．
先頭から任意のi文字列目までで，cnt = "'(' の数" >= "')' の数" を満たす時，その文字列は良い文字列となる．
従って，cnt の数を管理してシミュレーションを行えばよい．
ただしcnt < 0 になったタイミングは別で管理する必要があることに注意．
最悪計算量は，O(Q) < 10^7 となり高速．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;

int main(){
    int i,now = 0, min_minus_len;
    scanf("%d",&q);
    string t = "";
    const int Q = q + 1;
    min_minus_len = q + 1;
    while(q--){
        char c;
        getchar();
        scanf("%d", &i);
        if(i == 1){
            scanf(" %c",&c);
            now += c == '(' ? 1 : -1;
            t += c;
            if(now < 0)min_minus_len = min(min_minus_len, (int)t.size());
        }else{
            c = t.back();t.pop_back();
            now -= c == '(' ? 1 : -1;
            if(t.size() < min_minus_len)min_minus_len = Q;
        }
        printf("%s\n", now == 0 && t.size() < min_minus_len ? "Yes" : "No");
    }
    return 0;
}