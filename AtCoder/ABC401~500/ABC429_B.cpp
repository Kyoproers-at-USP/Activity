/*アルゴリズムと工夫点(N - 1/CPU: 1 ms Memory: 3880 KB  Length: 499 B)
全探索で解く．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i, sum_a = 0;
    scanf("%d%d",&n, &m);
    vector<int> a(n);
    rep(i,n){
        scanf("%d", &a[i]);
        sum_a += a[i];
    }
    rep(i,n){
        if(sum_a - a[i] == m){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}