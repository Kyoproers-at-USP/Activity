/*アルゴリズムと工夫点(AtCoder Language/CPU: 1 ms Memory: 3544 KB  Length: 428 B)
連想配列を使うと楽．
*/
#include<iostream>
#include<map>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    map<string,string> dict;
    dict["red"]="SSS";
    dict["blue"]="FFF";
    dict["green"]="MMM";
    cin>>s;
    if(dict.find(s)==dict.end())puts("Unknown");
    else printf("%s\n",dict[s].c_str());
    return 0;
}