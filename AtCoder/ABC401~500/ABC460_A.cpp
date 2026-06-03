/*アルゴリズムと工夫点(Mod While Positive/CPU: 1 ms Memory: 3828 KB  Length: 371 B)
言われた通りにシミュレーションをして解く．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    
    int ans = 0;
    while(m != 0){
        int x = n % m;
        m = x;
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}