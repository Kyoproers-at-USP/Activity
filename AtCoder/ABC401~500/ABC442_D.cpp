/*アルゴリズムと工夫点(Swap and Range Sum/CPU: 127 ms Memory: 7548 KB  Length: 3783 B)
BIT で解く．
最悪計算量は，O(N + Q * log2(N)) < 10 ^ 7 となり高速．
※ 公式解説ではクエリ1の差分に着目して累積和で解いていた
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef class BinaryIndexedTree{
    int MOD = 998244353;
    vector<ll> bit;
public:
    /// @brief BITのコンストラクタ
    /// @param n 要素数
    BinaryIndexedTree(int n = 0, int mod = -1){
        this -> bit = vector<ll>(n + 1, 0);
        this -> MOD = max(this -> MOD, mod);
    }

    /// @brief 初期化用
    /// @param n 要素数
    void init(int n){
        this -> bit = vector<ll>(n + 1, 0);
    }

    /// @brief 一つの要素への加算処理
    /// @param k 1-indexed で添え字指定(0を指定してはダメ)
    /// @param dx 加算する値
    void add(int k, long long dx){//k=0を代入してはダメ
        assert(1 <= k && k < (int)bit.size());
        while(k <= bit.size()){
            bit[k] = (bit[k] + dx) % MOD;
            k += (k & (-k));
        }
    }

    /// @brief bit[1,k]の合計値を得る
    /// @param k 
    /// @return bit[1,k]の合計値
    ll sum(int k)const{
        ll s = 0;
        while(k > 0){
            s = (s + this -> bit[k]) % this -> MOD;
            k -= (k & (-k));
        }
        return s;
    }

    /// @brief bit[l,r]の合計値
    /// @param l 閉区間の左端
    /// @param r 閉区間の右端
    /// @return 閉区間の合計値
    ll ssum(int l,int r)const{
        assert(1 <= l && l < bit.size());
        assert(1 <= r && r < bit.size());
        assert(l <= r);
        return (MOD + sum(r) - sum(l - 1)) % MOD;
    }

    /// @brief BITのサイズ
    /// @return BITの要素数
    int size(){
        return (int)bit.size();
    }

    /// @brief 配列の一要素へのアクセス
    /// @param id 添え字
    /// @return 指定した添え字に位置する値
    ll operator[](const int id)const{
        return this -> ssum(id, id);
    }

    /// @brief 並列二分探索で，閾値以上となる添え字探索
    /// @param sum_val 閾値
    /// @return 添え字
    int lowerBound(ll sum_val){
        int left = 0, right = this -> size(), mid;
        while(left < right){
            mid = (left + right) / 2;
            if(this -> sum(mid) < sum_val)left = mid + 1;
            else right = mid;
        }
        return left;
    }

    /// @brief 並列二分探索で，閾値より大きくなる添え字探索
    /// @param sum_val 閾値
    /// @return 添え字
    int upperBound(ll sum_val){
        int left = 0, right = this -> size(), mid;
        while(left < right){
            mid = (left + right) / 2;
            if(this -> sum(mid) <= sum_val)left = mid + 1;
            else right = mid;
        }
        return left;
    }

    /// @brief BITの中身を表示する
    void show(){
        int i;
        rep(i, bit.size() - 2)
            printf("%lld ", sum(i + 1) - sum(i));
        printf("%lld\n", sum(i + 1) - sum(i));
    }
}BIT;

int n, q;

int main(){
    int i, j;
    const int MAX = 2e9 + 1;
    scanf("%d%d", &n, &q);
    BIT tree(n, MAX);
    rep(i, n){
        int a;
        scanf("%d", &a);
        tree.add(i + 1, a);
    }
    while(q--){
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 1){
            int x, pre, nxt;
            scanf("%d", &x);
            pre = tree[x];
            nxt = tree[x + 1];
            tree.add(x, -pre);tree.add(x, nxt);
            tree.add(x + 1, -nxt);tree.add(x + 1, pre);
        }else if(tmp == 2){
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", tree.ssum(l, r));
        }
    }
    return 0;
}