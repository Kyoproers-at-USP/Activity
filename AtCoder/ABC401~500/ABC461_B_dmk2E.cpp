/*アルゴリズムと工夫点(The Honest Woodcutters/CPU: 1 ms Memory: 3768 KB  Length: 529 B)
各木こりi について走査して，「「木こりi が持っていたと主張する斧」を持っていた木こり」が，木こりi であるかで判定．
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
    rep(i, n){
        scanf("%d", &a[i]);
        a[i]--;
    }
    rep(i, n){
        scanf("%d", &b[i]);
        b[i]--;
    }

    rep(i, n)if(b[a[i]] != i){
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}