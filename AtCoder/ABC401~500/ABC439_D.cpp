/*アルゴリズムと工夫点(Kadomatsu Subsequence/CPU: 166 ms Memory: 9380 KB  Length: 1960 B)
辞書 + 時系列処理 で解く．
与えられた条件を下記のように呼称する．
・条件1_ Ai : Aj : Ak = 7 : 5 : 3
・条件2_ min(i, j, k) = j または max(i, j, k) = j
Aj を固定して，条件を満たす3つ組(i, j, k)の個数を数え上げる．
この時，Aj = A0, A1, A2... というように前から順に固定していく時系列処理を行う．
Aj = Ax とした時，この処理をしていく中で，A[0, x), A[x, N) の範囲それぞれで，値毎の個数を保持する辞書left, rightを持っておく．
Aj が5で割り切れる時，Ai, Ak の値は一意に定まるため，条件1を自然を満たす．
条件2の満たし方は2通りあり，それぞれ，leftとrightにおいて，Ai, Akの個数を参照し，組み合わせを計算すればよい．
最悪計算量は，O(N * log2(N))< 10^7 となり高速．
※ 本実装では高速化のため，辞書の代わりに座標圧縮を用いている
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef class CoordinatedCompression{
    bool initiated;
    vector<ll> xs;
public:
    CoordinatedCompression(){
        xs=vector<ll>(0);
        initiated=false;
    }
private:
    void init(){
        initiated=true;
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
    }
public:
    /// @brief 要素を追加する関数
    /// @param x 追加する座標
    void add(ll x){
        initiated=false;
        xs.push_back(x);
    }

    int operator()(ll k){
        if(!initiated)init();
        return lower_bound(xs.begin(),xs.end(),k)-xs.begin();
    }

    ll operator[](int id){
        if(!initiated)init();
        return xs[id];
    }

    /// @brief 座標圧縮後の座標総数を返す
    /// @return 座圧後の座標総数
    int size(){
        if(!initiated)init();
        return xs.size();
    }
}CC;

int n;

int main(){
    int i,j;
    ll ans = 0;
    scanf("%d", &n);
    vector<int> a(n);
    CC as;
    rep(i, n){
        scanf("%d", &a[i]);
        as.add(a[i]);
    }
    vector<int> left(as.size(), 0), right(as.size(), 0);
    rep(i, n)right[as(a[i])]++;
    rep(i, n){
        if(a[i] % 5 == 0){
            ll seven = (a[i] / 5) * 7, three = (a[i] / 5) * 3;
            int seven_id = as(seven), three_id = as(three);
            if(
                seven_id < as.size() && as[seven_id] == seven && 
                three_id < as.size() && as[three_id] == three
            )ans += (ll)left[seven_id] * left[three_id] + 
                    (ll)right[seven_id] * right[three_id];
        }
        left[as(a[i])]++;
        right[as(a[i])]--;
    }
    printf("%lld\n", ans);
    return 0;
}