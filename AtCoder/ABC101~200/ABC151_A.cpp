/*アルゴリズムと工夫点(Next Alphabet/CPU: 1 ms Memory: 3764 KB  Length: 254 B)
文字コードの連続性を利用して，実装を楽に．
※ 文字コードの特徴として，'0'~'9'に割り当てられるコードは連続値だが，'A'~'Z'などは必ずしも連続値ではないことに注意．
※ 競プロでは，アルファベットも連続した文字コードを持つと仮定してよい
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char c;

int main(){
    c = getchar();
    printf("%c\n", (int)c + 1);
    return 0;
}