/*アルゴリズムと工夫点(Max Straight/CPU: 98 ms Memory: 8996 KB  Length: 1844 B)
動的計画法で解く．
下記のテーブルを埋めていくことを考える．
dp[i] := (最後の要素の値がiである数列の最大の長さ)
ただし，要素の値は大きいため，座標圧縮を行う．
最悪計算量は，O(N * log2(N)) < 10 ^ 7
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
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
        xs=vector<T>(0);
        initiated = false;
    }
private:
    void init(){
        initiated=true;
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
    }
public:
    int operator()(T k){
        if(!initiated)init();
        return lower_bound(xs.begin(),xs.end(),k)-xs.begin();
    }

    T operator[](int id){
        if(!initiated)init();
        return xs[id];
    }

    /// @brief 要素を追加する関数
    /// @param x 追加する座標
    void add(T x){
        initiated = false;
        xs.push_back(x);
    }

    /// @brief 特定の要素が存在するか判定する関数
    /// @param x 対象要素
    /// @return 判定結果
    bool exist(T x){
        int x_id = (*this)(x);
        return x_id < xs.size() && xs[x_id] == x;
    }

    /// @brief 座標圧縮後の座標総数を返す
    /// @return 座圧後の座標総数
    int size(){
        if(!initiated)init();
        return xs.size();
    }
};

int n;

int main(){
    int i, ans = 0;
    scanf("%d", &n);
    vector<int> a(n);
    CC<int> as;
    rep(i, n){
        scanf("%d", &a[i]);
        as.add(a[i] - 1);as.add(a[i]);as.add(a[i] + 1);
    }
    vector<int> dp(as.size(), 0);
    rep(i, n){
        int now = as(a[i]), prev = as(a[i] - 1);
        dp[now] = max(dp[now], dp[prev] + 1);
        ans = max(ans, dp[now]);
    }
    printf("%d\n", ans);
    return 0;
}