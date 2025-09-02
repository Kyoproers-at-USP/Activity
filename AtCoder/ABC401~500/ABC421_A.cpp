/*アルゴリズムと工夫点(Misdelivery/CPU: 1 ms Memory: 3816 KB  Length: 394 B)
そのままやる．
※バーチャル参加
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,x;
string y;

int main(){
    int i,j;
    scanf("%d",&n);
    vector<string> s(n);
    rep(i,n)cin>>s[i];
    scanf("%d",&x);x--;
    cin>>y;
    printf("%s\n",s[x]==y?"Yes":"No");
    return 0;
}