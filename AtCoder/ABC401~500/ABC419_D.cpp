/*アルゴリズムと工夫点(Substr Swap/CPU: 48 ms Memory: 6492 KB  Length: 528 B)
imos法で解く．
Sの各文字が，M回の操作終了後に，SとTそれぞれどちらにあるかを判定できればよく，それは区間和を高速に計算すればよい．
最悪計算量は，O(N+M)<10^7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;
string s,t;

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    cin>>s>>t;
    vector<int> imos(n+1,0);
    while(m--){
        scanf("%d%d",&i,&j);
        imos[i-1]++;
        imos[j]--;
    }
    rep(i,n)imos[i+1]+=imos[i];
    rep(i,n)imos[i]%=2;
    rep(i,n)if(imos[i])s[i]=t[i];
    cout<<s<<endl;
    return 0;
}