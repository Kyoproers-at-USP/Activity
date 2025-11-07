/*アルゴリズムと工夫点(Double Helix/CPU: 1 ms Memory: 3732 KB  Length: 401 B)
各アルファベットの対を，配列を用いて管理．連想配列（c++ならmap）を使うと，実装がもっと楽．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define ALFA 26
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char b;

int main(){
    b = getchar();
    char ans[ALFA];
    ans['A' - 'A'] = 'T';
    ans['T' - 'A'] = 'A';
    ans['C' - 'A'] = 'G';
    ans['G' - 'A'] = 'C';
    printf("%c\n",ans[b - 'A']);
    return 0;
}