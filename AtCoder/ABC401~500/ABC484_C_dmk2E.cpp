/*アルゴリズムと工夫点(Move One Card/CPU: 24 ms Memory: 5236 KB  Length: 1796 B)
先頭から2回走査して解く．
もし1回の操作で A と B を一致させることができる場合，下記の性質が成り立つ．
 配列 A, B それぞれについて先頭から要素が一致するか判定し，添え字 i で不一致となった場合，
 下記の2パターンのどちらかの操作で成立する
  <i> 特定の要素 A_{k} (k > i)を，A_{i - 1}, A_{i} の間に挿入する
  <ii> 特定の要素 A_{i} を，A_{k}, A_{k + 1} (k > i) の間に挿入する
上記の2パターンのいずれかを満たすかどうかをシミュレーションでそれぞれ判定すればよい．
最悪計算量は，O(N) < 10 ^ 6 となり，十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;

    scanf("%d", &n);
    vector<int> a(n), b(n);
    rep(i, n)scanf("%d", &a[i]);
    rep(i, n)scanf("%d", &b[i]);

    auto ptn1 = [&]() -> bool{
        const int NIL = -1;
        int a_i = 0, b_i = 0, target_a = NIL;
        while(a_i < n || b_i < n){
            if(target_a == NIL){
                if(a[a_i] != b[b_i]){
                    target_a = b[b_i];
                    b_i++;
                }else{
                    a_i++;
                    b_i++;
                }
            }else{
                if(a[a_i] != b[b_i]){
                    if(a[a_i] == target_a)a_i++;
                    else return false;
                }else{
                    a_i++;
                    b_i++;
                }
            }
        }

        return true;
    };

    auto ptn2 = [&]() -> bool{
        const int NIL = -1;
        int a_i = 0, b_i = 0, target_a = NIL;
        while(a_i < n || b_i < n){
            if(target_a == NIL){
                if(a[a_i] != b[b_i]){
                    target_a = a[a_i];
                    a_i++;
                }else{
                    a_i++;
                    b_i++;
                }
            }else{
                if(a[a_i] != b[b_i]){
                    if(b[b_i] == target_a)b_i++;
                    else return false;
                }else{
                    a_i++;
                    b_i++;
                }
            }
        }

        return true;
    };

    printf("%s\n", ptn1() || ptn2() ? "Yes" : "No");
    return 0;
}