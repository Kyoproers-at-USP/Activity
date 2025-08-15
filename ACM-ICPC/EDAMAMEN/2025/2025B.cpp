/*アルゴリズムと工夫点(接頭辞と接尾辞を同じに/CPU: ? ms Memory: ? KB  Length: - B)
2つのsを順次スライドさせて解を求める。
sを2つ用意して，それぞれs1, s2とする．s2の先頭をs1の2文字目に合わせたものを初期位置とした後，s2を順次スライドさせる．
s1とs2の重なっている範囲の文字列が完全に一致した時，s1+(重なる部分を除いたs2)が解となる．
最悪計算量は，O(|s|^2)<10^4 となり十分高速．
実装担当：N
*/
#include<iostream>
#include<cassert>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<algorithm>
// #include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int i,j;
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        string s;
        cin >> s;

        bool ok=false;

        int cnt;
        for(int i=1;i<n;i++){
            if(s.substr(i,s.size()-i)==s.substr(0,s.size()-i)){
                cout << s << s.substr(n-i) << endl;
                ok=true;
                break;
            }
        }
        if(ok==false){
            cout << s << s << endl;
        }
    }
    return 0;
}