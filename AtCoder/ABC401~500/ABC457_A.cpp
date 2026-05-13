/*アルゴリズムと工夫点(Array/CPU: 2 ms Memory: 3868 KB  Length: 373 B)
入力データを一次元配列で保持し，指定された要素を出力すればよい．
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
    
    vector<int> a(n);
    rep(i, n)scanf("%d", &a[i]);
    scanf("%d", &i);
    printf("%d\n", a[i - 1]);
    return 0;
}