/*アルゴリズムと工夫点(Append s/CPU: 2 ms Memory: 3588 KB  Length: 248 B)
言われた通りにやる．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;
    cout << s + 's' << endl;
    return 0;
}