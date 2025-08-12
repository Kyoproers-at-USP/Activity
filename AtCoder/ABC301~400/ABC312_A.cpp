/*アルゴリズムと工夫点(Chord/CPU: 1 ms Memory: 3704 KB  Length: 412 B)
そのまま．
setとか使っても良かったかも．
*/
#include<iostream>
#include<set>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;
const string target[]={"ACE","BDF","CEG","DFA","EGB","FAC","GBD"};
const int MAX_T=7;

int main(){
    int i;
    cin>>s;
    rep(i,MAX_T)if(target[i]==s)break;
    printf("%s\n",i==MAX_T?"No":"Yes");
    return 0;
}