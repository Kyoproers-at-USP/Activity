/*アルゴリズムと工夫点(Draw Frame/CPU: 2 ms Memory: 3864 KB  Length: 528 B)
2種のWマスからなる1行を保持し，適切に出力すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w;

int main(){
    int i, j;
    scanf("%d%d", &h, &w);
    string black_line = "";
    rep(i, w)black_line += "#";
    
    string normal_line = "#";
    rep(i, w - 2)normal_line += ".";
    normal_line += "#";

    cout << black_line << '\n';
    rep(i, h - 2)cout << normal_line << '\n';
    cout << black_line << '\n';
    return 0;
}