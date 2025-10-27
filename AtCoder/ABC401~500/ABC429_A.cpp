/*アルゴリズムと工夫点(Too Many Requests/CPU: 1 ms Memory: 3684 KB  Length: 305 B)
言われた通りにやる．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i;
    scanf("%d%d",&n,&m);
    rep(i,n)printf("%s\n", i < m ? "OK" : "Too Many Requests");
    return 0;
}