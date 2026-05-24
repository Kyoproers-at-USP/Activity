/*アルゴリズムと工夫点(Chalkboard Median/CPU: 131 ms Memory: 9900 KB  Length: 6005 B)
座標圧縮 + BIT で解く．
Ai, Bi の値がそれぞれ大きいため，座標圧縮を行った値を用いる．
この値を用いてBIT上で，値毎の現在の個数を保持して置く．
そうすると，先頭からの累積和が，丁度 floor((現在の個数 + 1) / 2) になる座圧後の値が，各クエリ毎の解となる．
この時，座圧後の各値を座圧前に戻せるよう，実装しておくこと．
最悪計算量は，O(Q * log2(Q)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
class CC{
    bool initiated;
    vector<T> xs;
public:
    /// @brief 座標圧縮（CoordinatedCompression）のクラス
    CC(){
        xs = vector<T>(0);
        initiated = false;
    }
private:
    void init(){
        initiated = true;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }
public:
    int operator()(T value){
        if(!initiated)init();
        return lower_bound(xs.begin(), xs.end(), value) - xs.begin();
    }

    T operator[](int id){
        if(!initiated)init();
        return xs[id];
    }

    /// @brief 要素を追加する関数
    /// @param value 追加する座標
    void add(T value){
        initiated = false;
        xs.push_back(value);
    }

    /// @brief 特定の要素が存在するか判定する関数
    /// @param value 対象要素
    /// @return 判定結果
    bool exist(T value){
        int value_id = (*this)(value);
        return value_id < xs.size() && xs[value_id] == value;
    }

    /// @brief 座標圧縮後の座標総数を返す
    /// @return 座圧後の座標総数
    int size(){
        if(!initiated)init();
        return xs.size();
    }
};

typedef class BinaryIndexedTree{
    ll mod = 998244353;
    vector<ll> bit;
public:
    /// @brief BITのコンストラクタ
    /// @param len 要素数
    /// @param mod 除数
    BinaryIndexedTree(int len = 0, ll mod = -1){
        this -> bit = vector<ll>(len + 1, 0);
        this -> mod = max(this -> mod, mod);
    }

    /// @brief 初期化用
    /// @param len 要素数
    void init(int len){
        this -> bit = vector<ll>(len + 1, 0);
    }

    /// @brief 一つの要素への加算処理
    /// @param id 1-indexed で添え字指定(0を指定してはダメ)
    /// @param value 加算する値
    void add(int id, long long value){//id = 0を代入してはダメ
        assert(1 <= id && id < (int)bit.size());
        while(id <= bit.size()){
            bit[id] = (bit[id] + value) % this -> mod;
            id += (id & (-id));
        }
    }

    /// @brief bit[1,k]の合計値を得る
    /// @param right_id 
    /// @return bit[1,k]の合計値
    ll sum(int right_id)const{
        ll ans = 0;
        while(right_id > 0){
            ans = (ans + this -> bit[right_id]) % this -> mod;
            right_id -= (right_id & (-right_id));
        }
        return ans;
    }

    /// @brief bit[l,r]の合計値
    /// @param l 閉区間の左端
    /// @param r 閉区間の右端
    /// @return 閉区間の合計値
    ll ssum(int l,int r)const{
        assert(1 <= l && l < bit.size());
        assert(1 <= r && r < bit.size());
        assert(l <= r);
        return (this -> mod + sum(r) - sum(l - 1)) % this -> mod;
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

    /// @brief その合計値をとる区間 [1, k] において，最大のkを返す（最悪計算量 log2(配列のサイズ)）
    /// @param sum 合計値
    /// @return int型（1-indexed の値）
    int getMaxIdOfSum(ll sum)const{
        int id = 0, power_of_two = 1;
        while((power_of_two << 1) < bit.size())power_of_two <<= 1;
        for(;power_of_two > 0;power_of_two >>= 1){
            if(id + power_of_two >= bit.size())continue;
            if(bit[id + power_of_two] <= sum){
                sum -= bit[id + power_of_two];
                id += power_of_two;
            }
        }
        return id;
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

    /// @brief BITで保持している配列を表示する
    void showBITArr(){
        int i;
        rep(i, bit.size())printf("id = %d: %lld\n", i, bit[i]);
    }
}BIT;

int x, q;

int main(){
    int i, j;
    
    scanf("%d%d", &x, &q);
    CC<int> xs;xs.add(/* value = */ 0);
    xs.add(/* value = */ x);
    
    vector<int> a(q), b(q);
    rep(i, q){
        scanf("%d%d", &a[i], &b[i]);
        xs.add(/* value = */ a[i]);
        xs.add(/* value = */ b[i]);
    }

    BIT tree(xs.size());
    tree.add(/* id = */ xs(/* value = */ x), /* value = */ 1);
    rep(i, q){
        tree.add(/* id = */ xs(/* value = */ a[i]), /* value = */ 1);
        tree.add(/* id = */ xs(/* value = */ b[i]), /* value = */ 1);

        printf("%d\n", xs[tree.getMaxIdOfSum(/* sum = */ i + 1) + 1]);
    }
    return 0;
}