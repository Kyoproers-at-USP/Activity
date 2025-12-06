/*アルゴリズムと工夫点(1122 Substring 2/CPU: 22 ms Memory: 13744 KB  Length: 723 B)
ランレングス圧縮で解く．
連続部分文字列で1122文字列であるものを探索するため，連続する数値が隣り合う2つの「数の塊」にのみ着目し，数え上げればよい．
最悪計算量は，O(N) < 10^7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<char,int> P; // (number, count)

string s;

int main(){
    int i,j;
    ll ans = 0;
    cin >> s;
    vector<P> rle;
    i = 0;
    while(i < s.length()){
        P now(s[i], 1);
        i++;
        while(i < s.length() && s[i] == now.first){
            now.second++;
            i++;
        }
        rle.push_back(now);
    }
    rep(i,rle.size() - 1){
        if(rle[i].first - '0' == rle[i + 1].first - '1')ans += min(rle[i].second,rle[i + 1].second);
    }
    printf("%lld\n",ans);
    return 0;
}