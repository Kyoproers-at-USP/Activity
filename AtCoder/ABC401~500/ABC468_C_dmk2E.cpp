/*アルゴリズムと工夫点(Between P and Q/CPU: 38 ms Memory: 3900 KB  Length: 812 B)
Pより大きくQより小さい数列の順列を順番に全列挙して数え上げる．
N <= 10 であるため，[1, 10] の値を [0, 9] の値に変換し，各数列を文字列として扱うと実装が楽．
最悪計算量は，O(N * N!) < 10 ^ 8 となり間に合う．
*/
#include<iostream>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

char parseNum(int num){
    return (char)(num - '1' + '0');
};

int main(){
    int i;

    scanf("%d", &n);
    string p = "";
    rep(i, n){
        int x;
        scanf("%d", &x);
        p += parseNum(/* num = */ x);
    }
    string q = "";
    rep(i, n){
        int x;
        scanf("%d", &x);
        q += parseNum(/* num = */ x);
    }

    int ans = 0;
    if(p < q){
        next_permutation(p.begin(), p.end());
        do{
            if(p == q)break;
            ans++;
        }while(next_permutation(p.begin(), p.end()));
    }
    printf("%d\n", ans);
    return 0;
}