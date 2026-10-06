/*アルゴリズムと工夫点(Sort Subarray/CPU: 16 ms Memory: 11772 KB  Length: 2695 B)
ダブルスタックキューを用いて解く．
まず下記の部分列が昇順となるような，max_begin, min_end をそれぞれ求めておく．
 ・a[1, max_begin]
 ・a[min_end, n + 1)

長さがKの区間を順にずらしていき，
着目しているK個の部分列における最小値と最大値を高速に求めることを考える．
これはダブルスタックキューで実現可能である．
この時の最小・最大の値と，着目区間の前後の配列A上の値との大小関係に着目すれば，条件を満たすかは判定可能である．
ただしK個の連続部分列の範囲について，先頭の添え字は max_begin 以下で，
末尾の添え字は min_end 以上でないといけない点に注意．
最悪計算量は，O(N) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<typename T, auto op>
class DoubleStackQueue{
    typedef pair<T, T> P; // (val, range_op)

    vector<P> left, right;

public:
    DoubleStackQueue(){
        this -> left = vector<P>();
        this -> right = vector<P>();
    }

    void push(T val){
        this -> left.push_back(P(
            val, 
            this -> left.size() > 0 ? op(val, this -> left.back().second) : val
        ));
    }

    void moveLeftToRight(){
        while(left.size()){
            auto [val, _] = left.back();left.pop_back();
            this -> right.push_back(P(
                val, 
                this -> right.size() > 0 ? op(val, this -> right.back().second) : val
            ));
        }
    }

    P pop(){
        if(right.size() == 0)this -> moveLeftToRight();

        auto ans = right.back();right.pop_back();
        return ans;
    }

    T getBestOp(){
        T best_val;

        if(left.size()){
            auto [_, left_best] = left.back();
            best_val = left_best;
        }
        if(right.size()){
            auto [_, right_best] = right.back();
            if(left.size())best_val = op(best_val, right_best);
            else best_val = right_best;
        }

        return best_val;
    }

    int size(){
        return left.size() + right.size();
    }
};

int n, k;

int maxOp(int a, int b){return max(a, b);}
int minOp(int a, int b){return min(a, b);}

int main(){
    int i;

    scanf("%d%d", &n, &k);
    vector<int> a(n);
    rep(i, n)scanf("%d", &a[i]);

    DoubleStackQueue<int, maxOp> max_range_k;
    DoubleStackQueue<int, minOp> min_range_k;
    rep(i, k){
        max_range_k.push(/* val = */ a[i]);
        min_range_k.push(/* val = */ a[i]);
    }

    int max_begin = 0;
    while(max_begin < n && a[max_begin] <= a[max_begin + 1])max_begin++;
    int min_end = n - 1;
    while(min_end > 0 && a[min_end - 1] <= a[min_end])min_end--;

    int begin = 0, end = k;
    while(end <= n){
        if(begin <= max_begin && end >= min_end && (
            begin <= 0 || a[begin - 1] <= min_range_k.getBestOp()
        ) && (
            end >= n || max_range_k.getBestOp() <= a[end]
        )){
            puts("Yes");
            return 0;
        }

        max_range_k.pop();
        min_range_k.pop();
        max_range_k.push(/* val = */ a[end]);
        min_range_k.push(/* val = */ a[end]);
        begin++;end++;
    }
    puts("No");
    return 0;
}