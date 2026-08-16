/*アルゴリズムと工夫点(Keep the Change/CPU: 1 ms Memory: 3908 KB  Length: 494 B)
Y, X の値をシミュレーションで求めて，Y - X を出力する．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define BUDGET 10000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;
    
    scanf("%d", &n);
    int y = BUDGET, x = BUDGET;
    while(n--){
        int a, b;
        string s;
        cin >> a >> b >> s;

        y -= a;
        if(s == "keep")x -= b;
        else x -= a;
    }

    printf("%d\n", y - x);
    return 0;
}