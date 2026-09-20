/*アルゴリズムと工夫点(Cantrip/CPU: 50 ms Memory: 10324 KB  Length: 417 B)
解を観察し，得た特徴を元に解く．
下記の配列を前処理で求めておく．
 kth_id[k] := 先頭に近い方からk番目の'x'が，S上で先頭から何番目に存在するか保持
サンプルテストケースなどで解を観察すると，k = i の時，kth_id[i] が解となっていることが分かる．
これを利用すれば，最悪計算量 O(N) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(){
    int i, j;

    cin >> n >> s;
    vector<int> kth_id;
    rep(i, n)if(s[i] == 'x')kth_id.push_back(i);

    rep(i, n)printf("%d\n", i < kth_id.size() ? kth_id[i] + 1 : n);
    return 0;
}