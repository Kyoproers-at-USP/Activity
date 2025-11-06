/*アルゴリズムと工夫点(Neighbor Distance/CPU: 698 ms Memory: 34980 KB  Length: 2384 B)
setを用いた状態の差分管理で解く．
人1,2,...i-1 までが数直線上に立っている時，dの総和を sum_d(i - 1) とする．
この時，配列d[x] = (人xに最も近い別の人までの距離) とする．
人iが新たに立つことによる変化は，その前後の計2人のd[x]の変化となり，人iの前後の人のd[x]の更新はO(1)で可能．
その差分とsum_d(i - 1)を用いてsum_d(i)を求められる．
最悪計算量は，O(N * log2(N)) < 10^7 となり高速．
※ mapではなく座圧を用いて定数倍速くしている
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef class CoordinatedCompression{
    bool initiated;
    vector<int> xs;
public:
    CoordinatedCompression(){
        xs=vector<int>(0);
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
    void add(int x){
        initiated=false;
        xs.push_back(x);
    }

    int operator()(int k){
        if(!initiated)init();
        return lower_bound(xs.begin(),xs.end(),k)-xs.begin();
    }

    int operator[](int id){
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
    const int NIL = (2e9);
    ll ans = 0;
    scanf("%d",&n);
    vector<int> x(n + 1);
    CC xs;
    x[0] = 0;
    xs.add(0);
    rep(i,n){
        scanf("%d",&x[i + 1]);
        xs.add(x[i + 1]);
    }
    vector<int> x_to_d(xs.size(),NIL);
    set<int> st;
    st.insert(0);
    for(i = 1;i < n + 1;i++){
        set<int>::iterator it = st.upper_bound(x[i]);
        int min_d = NIL;
        // x after the x[i]
        if(it != st.end()){
            int nxt = *it, nxt_id = xs(nxt);
            if(x_to_d[nxt_id] != NIL)ans -= x_to_d[nxt_id];
            x_to_d[nxt_id] = min(x_to_d[nxt_id], abs(nxt - x[i]));
            ans += x_to_d[nxt_id];
            min_d = min(min_d, abs(nxt - x[i]));
        }
        // x before the x[i]
        it--;
        int pre = *it, pre_id = xs(pre);
        if(x_to_d[pre_id] != NIL)ans -= x_to_d[pre_id];
        x_to_d[pre_id] = min(x_to_d[pre_id], abs(pre - x[i]));
        ans += x_to_d[pre_id];
        min_d = min(min_d, abs(pre - x[i]));
        // x[i]
        int x_id = xs(x[i]);
        x_to_d[x_id] = min_d;
        ans += x_to_d[x_id];

        st.insert(x[i]);
        printf("%lld\n",ans);
    }
    return 0;
}