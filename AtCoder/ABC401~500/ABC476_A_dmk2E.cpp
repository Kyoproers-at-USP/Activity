/*アルゴリズムと工夫点(Appender/CPU: 1 ms Memory: 3624 KB  Length: 281 B)
言われた通りに条件分岐をして解く．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;
    cout << s << (s.back() == 'e' ? "r" : "er") << endl;
    return 0;
}