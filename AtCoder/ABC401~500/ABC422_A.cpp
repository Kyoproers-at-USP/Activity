/*アルゴリズムと工夫点(Stage Clear/CPU: 1 ms Memory: 3812 KB  Length: 413 B)
工夫して，場合分けを減らす．
ワールド番号wとステージ番号sを 0-indexed で捉え，現在のステージを`e = w*8 + s`という値に変換して考える．
すると，`e/8 - e%8` が答え．
※ バーチャル参加
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    char w,s;
    scanf("%c-%c",&w,&s);
    int ans_i = w-'0',ans_j = s-'0';
    ans_i--;ans_j--;
    int temp = ans_i*8+ans_j + 1;
    ans_i = temp / 8;
    ans_j = temp % 8;
    printf("%d-%d\n",ans_i+1,ans_j+1);
    return 0;
}