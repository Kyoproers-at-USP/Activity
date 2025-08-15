/*アルゴリズムと工夫点(You're a teapot/CPU: 1 ms Memory: 3884 KB  Length: 609 B)
全探索．
出力値の桁数に注意．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

double calc(string s){
    int i,j=0;
    if(s.length()>=3&&s[0]==s[s.length()-1]&&s[0]=='t'){
        rep(i,s.length())j+=(s[i]=='t');
        return (j-2.0)/(s.length()-2.0);
    }else
        return 0.0;
}

int main(){
    int i,j;
    double ans=0.0;
    cin>>s;
    rep(i,s.length())rep(j,i){
        string str=s.substr(j,i-j+1);
        ans=max(ans,calc(str));
    }
    printf("%.12f\n",ans);
    return 0;
}