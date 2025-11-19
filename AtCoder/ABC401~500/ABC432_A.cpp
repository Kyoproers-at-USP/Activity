/*アルゴリズムと工夫点(Permute to Maximize/CPU: 1 ms Memory: 3596 KB  Length: 396 B)
A,B,Cを値の降順にソートして繋げ合わせる．
*/
#include<iostream>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string ipt = "";

int main(){
    int n = 3;
    while(n--){
        string tmp;
        cin >> tmp;
        ipt += tmp;
    }
    sort(ipt.rbegin(),ipt.rend());
    cout << ipt << endl;
    return 0;
}