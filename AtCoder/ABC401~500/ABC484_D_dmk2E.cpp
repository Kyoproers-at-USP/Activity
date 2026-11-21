/*アルゴリズムと工夫点(Move One Card Left/CPU: 14 ms Memory: 6860 KB  Length: 881 B)
ランレングス圧縮 + 時系列処理 で解く．
取り出すAの要素を左から順次固定した時の，有りうる列の種類を重複なく数え上げること考える．
その要素の値がその要素の前後に存在する場合の有りうる列数は，その内一番左端の要素を取り出した場合に集約される．
従って，A はランレングス圧縮したものを扱う．
また取り出すAの要素の値がそれより左側に存在しない場合は，その位置の 0-indexed の添え字の値が有りうる列数となる．
逆に存在する場合は被りが無いように数え上げる必要があり，
添え字の値から (その要素を含む，RLE 後の要素集合の長さ + 1) だけ引いた値が解となる．
従って最悪計算量は，O(N) < 10 ^ 6 となり，十分高速．
※ 上記の性質は，実際に紙上で書いて閃きました
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P; // (val, cnt)

int n;

int main(){
    int i, j;

    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n){
        scanf("%d", &a[i]);
        a[i]--;
    }

    vector<P> rle;
    i = 0;
    while(i < n){
        P nxt(a[i], 1);
 
        j = i + 1;
        while(j < n && a[j] == a[i]){
            nxt.second++;
            j++;
        }
        rle.push_back(nxt);

        i = j;
    }

    vector<int> val_to_cnt(n, 0);
    ll ans = 1;
    i = 0;
    for(auto [val, cnt] : rle){
        ans += i - val_to_cnt[val];

        val_to_cnt[val] += cnt;
        i += cnt;
    }

    printf("%lld\n", ans);
    return 0;
}
