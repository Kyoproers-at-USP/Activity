/*アルゴリズムと工夫点(居合を終え、青い絵を覆う/CPU: 1 ms Memory: 3628 KB  Length: 354 B)
母音を文字列で保持し，いずれの1文字とも一致しないかで判定．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char c;
string boin = "aiueo";

int main(){
    c = getchar();
    for(char b : boin)if(b == c){
        puts("vowel");
        return 0;
    }
    puts("consonant");
    return 0;
}