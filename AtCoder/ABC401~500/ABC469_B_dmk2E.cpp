/*アルゴリズムと工夫点(Isolated Seats/CPU: 2 ms Memory: 3764 KB  Length: 537 B)
N個の椅子一つ一つについて条件を満たすか判定していけばよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(){
    int i;
    cin >> n >> s;

    auto judge = [&](int id) -> int{
        return s[id] == 'x' && 
               (id - 1 < 0 | s[id - 1] == 'x') && 
               (id + 1 >= s.length() | s[id + 1] == 'x');
    };
    int ans = 0;
    rep(i, s.length())ans += judge(/* id = */ i);

    printf("%d\n", ans);
    return 0;
}