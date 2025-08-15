/*アルゴリズムと工夫点(I'm a teapot/CPU: 1 ms Memory: 3672 KB  Length: 290 B)
t.substr(n-3,3)=="tea"で判定．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string t;

int main(){
    cin>>n>>t;
    printf("%s\n",(n>=3&&t.substr(n-3,3)=="tea")?"Yes":"No");
    return 0;
}