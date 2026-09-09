/*アルゴリズムと工夫点(Exit Order/CPU: 1 ms Memory: 3728 KB  Length: 699 B)
シミュレーションして解く．
先頭から10人グループずつ下記の条件を満たすか判定していけばよい．
 <i> 座席番号の値が適切な範囲内であるか
 <ii> その座席番号は既に出現していないか
工夫することで，最悪計算量 O(N) で解ける．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_NUM 10
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;

    scanf("%d", &n);
    int is_exist = 0, now_diff = -MAX_NUM;
    rep(i, n){
        if(i % MAX_NUM == 0){
            is_exist = 0;
            now_diff += MAX_NUM;
        }

        int p;
        scanf("%d", &p);
        p--;
        p -= now_diff;

        if(p >= MAX_NUM || p < 0 || ((is_exist >> p) & 1)){
            puts("No");
            return 0;
        }else is_exist |= (1 << p);
    }

    puts("Yes");
    return 0;
}